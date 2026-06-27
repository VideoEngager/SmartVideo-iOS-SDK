//
//  CoBrowseEngine.swift
//  SmartVideo
//
//  Created by Slav Sarafski on 30.11.23.
//

import Foundation
import CobrowseIO

public class CoBrowseEngine: SmartVideoEngine {
    
    private var tenantId: String
    private var engineUrl: String
    
    public weak var delegate: CoBrowseEngineDelegate?
    
    public init(engineUrl: String, tenantId: String)
    {
        self.engineUrl = engineUrl
        self.tenantId = tenantId
    }
    
    
    public func connect() {
        ConnectionData.shared.baseURL = self.engineUrl
        RestManager.shared.requestBrokeragesBy(tenantId: self.tenantId) { [weak self] info, _ in
            if let cobrowse = info?.cobrowse,
               cobrowse.enabled,
               let license = cobrowse.license {
                self?.startCobrowse(license: license)
            }
        }
    }
    
    private func startCobrowse(license: String) {
        DispatchQueue.main.async {
            CobrowseIO.instance().license = license
            CobrowseIO.instance().start()
            CobrowseIO.instance().createSession { [weak self] _, session in
                if let session {
                    self?.send(session: session)
                }
            }
        }
    }
    
    private func send(session: CBIOSession) {
        if let code = session.code(),
           let id = session.id() {
            RestManager.shared.createByVisitor(tenantId: self.tenantId, code: code, session: id) { [weak self] _, _ in
                 self?.delegate?.cobrowseDidSet(code: code)
            }
        }
    }
    
    public func disconnect() {
        
    }
    
    public func applicationDidBecomeActive() {
        
    }
    
    public func sendChat(message: ChatMessage) {
        
    }
    
    public var hasVideo: Bool {
        false
    }
}

public protocol CoBrowseEngineDelegate: AnyObject {
    func cobrowseDidSet(code: String)
}

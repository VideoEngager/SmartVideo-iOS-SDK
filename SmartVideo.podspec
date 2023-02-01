
Pod::Spec.new do |spec|

  spec.name         = "SmartVideo"
  spec.version      = "1.14.0"
  spec.summary      = "SmartVideo iOS Swift SDK"
  spec.description  = "The SmartVideo SDK for iOS allows you to integrate SmartVideo application in your own iOS mobile applications. This way, you would enable your customers to call your Genesys Cloud, Genesys Engage, or VideoEngager agents directly from your iOS application through Click to Audio/Video type of functionality."
  spec.platform = :ios
  spec.ios.deployment_target = '13.0'

  spec.homepage = 'https://github.com/VideoEngager/SmartVideo-iOS-SDK'
  spec.license = { :type => "MIT", :file => "LICENSE" }
  spec.authors = { 'VideoEngager' => 'support@videoengager.com' }
  spec.source = { :git => 'https://github.com/VideoEngager/SmartVideo-iOS-SDK.git', :tag => spec.version }
  spec.vendored_frameworks = 'SmartVideoSDK.xcframework'

  spec.dependency 'WebRTC-lib', '104.0.0'
  spec.dependency 'CocoaAsyncSocket', '7.6.5'

end
 
 

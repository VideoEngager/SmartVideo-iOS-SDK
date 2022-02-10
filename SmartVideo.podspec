#
#  Be sure to run `pod spec lint SmartVideo.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  spec.name         = "SmartVideo"
  spec.version      = "1.4.0"
  spec.summary      = "SmartVideo iOS Swift SDK"
  spec.description  = "The SmartVideo SDK for iOS allows you to integrate SmartVideo application in your own iOS mobile applications. This way, you would enable your customers to call your Genesys Cloud, Genesys Engage, or VideoEngager agents directly from your iOS application through Click to Audio/Video type of functionality."
  spec.platform = :ios
  spec.ios.deployment_target = '13.0'

  spec.homepage = 'https://github.com/VideoEngager/SmartVideo-iOS-SDK'
  spec.license = { :type => "MIT", :file => "LICENSE" }
  spec.authors = { 'VideoEngager' => 'support@videoengager.com' }
  spec.source = { :git => 'https://github.com/VideoEngager/SmartVideo-iOS-SDK.git', :tag => spec.version }
  spec.source_files  = "SmartVideo.framework/Headers/**/*.h"
  spec.public_header_files = "SmartVideo.framework/Headers/**/*.h"
  spec.vendored_frameworks = "SmartVideo.framework"

  spec.pod_target_xcconfig = { 
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' 
  }
  
  spec.user_target_xcconfig = { 
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }

  spec.dependency 'GoogleWebRTC'

end

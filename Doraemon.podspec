Pod::Spec.new do |s|
  s.name         = "Doraemon"
  s.version      = "0.1"
  s.summary      = "Doraemon"
  s.homepage     = "http://www.cleverloop.org"
  s.author       = { "XueMingxiang" => "xuemx@cleverloop.com" }
  s.platform     = :ios, "7.0"
  s.source       = {
    :git => "https://github.com/UzxMx/Doraemon.git"
  }
  s.source_files = 'Doraemon.framework/**/*.h'
  s.public_header_files = "Doraemon.framework/**/*.h"
  s.vendored_frameworks = "Doraemon.framework"
  s.header_mappings_dir = "Doraemon.framework"
  s.libraries = "c++", "iconv", "resolv"
  s.frameworks = "JavaScriptCore", "VideoToolbox", "AssetsLibrary", "CoreVideo", "CoreAudio", "CoreGraphics", "OpenGLES", "WebKit"
  s.requires_arc = true
end

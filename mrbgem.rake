MRuby::Gem::Specification.new('esp32-ext_esp_err') do |spec|
  spec.license = 'MIT'
  spec.author  = 'Seiei Miyagi'
  spec.summary = 'ESP-IDF esp_err.h constants'
  
  spec.cc.include_paths << "#{build.root}/include"
end

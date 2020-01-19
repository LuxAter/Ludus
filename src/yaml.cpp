#include "yaml.hpp"

#include <string>

#include <yaml-cpp/yaml.h>

#include "fs.hpp"
#include "log.hpp"

ludus::Yaml::Yaml() {}
ludus::Yaml::Yaml(const std::string &src) : node(YAML::Load(src)) {}
ludus::Yaml::Yaml(const YAML::Node &node) : node(node) {}
ludus::Yaml::~Yaml() {}

ludus::Yaml ludus::Yaml::load(const std::string &file) {
  if (fs::exists(file)) {
    return Yaml(YAML::LoadFile(file));
  } else {
    LWARN("YAML file does not exist \"{}\"", file);
    return Yaml();
  }
}
ludus::Yaml ludus::Yaml::load(const std::string &file,
                              const Yaml &default_value) {
  if (fs::exists(file)) {
    return Yaml(YAML::LoadFile(file));
  } else {
    return default_value;
  }
}
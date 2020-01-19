#include "yaml.hpp"

#include <cstdio>
#include <sstream>
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
void ludus::Yaml::save(const std::string &file, const Yaml &data) {
  if (!fs::exists(file)) {
    fs::create_directories(fs::path(file).parent_path());
  }
  FILE *out_file = std::fopen(file.c_str(), "w");
  if (!out_file) {
    LWARN("Failed to open YAML file \"{}\" for writting", file);
  } else {
    std::fprintf(out_file, "%s", data.string().c_str());
    std::fclose(out_file);
  }
}

std::string ludus::Yaml::string() const {
  std::stringstream out;
  out << node;
  return out.str();
}
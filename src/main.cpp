#include <cmath>
#include <iostream>

#include "fs.hpp"
#include "log.hpp"
#include "yaml.hpp"

int main(int argc, char const *argv[]) {
  ludus::logger::initalize_core_logger();
  ludus::Yaml config =
      ludus::Yaml::load(ludus::fs::get_config_dir().append("ludus/config.yml"),
                        ludus::Yaml("version: 0.1.0"));
  LINFO("Default CONFIG: {}", config.string());
  ludus::Yaml::save(ludus::fs::get_config_dir().append("ludus/config.yml"),
                    config);
  return 0;
}

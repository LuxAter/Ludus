#include <cmath>
#include <iostream>

#include "fs.hpp"
#include "log.hpp"
#include "yaml.hpp"

int main(int argc, char const *argv[]) {
  ludus::logger::initalize_core_logger();
  ludus::logger::core::info("Data Dir: {}", ludus::fs::get_data_dir().string());
  ludus::logger::core::info("Config Dir: {}",
                            ludus::fs::get_config_dir().string());
  return 0;
}

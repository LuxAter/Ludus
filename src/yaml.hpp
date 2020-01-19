#ifndef LUDUS_YAML_HPP_
#define LUDUS_YAML_HPP_

#include <string>

#include <yaml-cpp/yaml.h>

namespace ludus {
class Yaml {
public:
  Yaml();
  Yaml(const std::string &src);
  Yaml(const YAML::Node &node);
  ~Yaml();

  static Yaml load(const std::string &file);
  static Yaml load(const std::string &file, const Yaml &default_value);
  static void save(const std::string &file, const Yaml &data);

  std::string string() const;

  template <typename T> inline YAML::Node operator[](const T &key) {
    return node[key];
  }
  template <typename T>
  inline const YAML::Node &operator[](const T &key) const {
    return node[key];
  }

  inline YAML::Node &get_node() { return node; }
  inline const YAML::Node &get_node() const { return node; }

private:
  YAML::Node node;
};
} // namespace ludus

#endif // LUDUS_YAML_HPP_
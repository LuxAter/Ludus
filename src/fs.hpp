#ifndef LUDUS_FS_HPP_
#define LUDUS_FS_HPP_

#if defined(__cplusplus) && __cplusplus >= 201703L && defined(__has_include)
#if __has_include(<filesystem>)
#define GHC_USE_STD_FS
#include <filesystem>
namespace ludus {
namespace fs {
  using namespace std::filesystem;
  fs::path get_data_home();
} // namespace fs
} // namespace ludus
#endif
#endif
#ifndef GHC_USE_STD_FS
#include <ghc/filesystem.hpp>
namespace ludus {
namespace fs {
  using namespace ghc::filesystem;
} // namespace fs
} // namespace ludus
#endif

namespace ludus {
namespace fs {
  path get_home_dir();
  path get_data_dir();
  path get_config_dir();
  path get_cache_dir();
} // namespace fs
} // namespace ludus

#endif // LUDUS_FS_HPP_
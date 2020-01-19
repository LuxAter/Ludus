#include "fs.hpp"

#ifndef _WIN32
#include <pwd.h>
#include <unistd.h>

ludus::fs::path ludus::fs::get_home_dir() {
  int uid = getuid();
  const char *home_env = std::getenv("HOME");
  if (uid != 0 && home_env) {
    return ludus::fs::path(home_env);
  }
  struct passwd *pw = nullptr;
  struct passwd pwd;
  long buff_size = sysconf(_SC_GETPW_R_SIZE_MAX);
  if (buff_size < 0) {
    buff_size = 0xff;
  }
  char *buffer = (char *)std::malloc(sizeof(char) * buff_size);
  int error_code = getpwuid_r(uid, &pwd, buffer, buff_size, &pw);
  free(buffer);
  if (error_code) {
    throw std::runtime_error("Unabled to get passwd struct.");
  }
  const char *tmp_res = pw->pw_dir;
  if (!tmp_res) {
    throw std::runtime_error("Useer has no home directory");
  }
  return ludus::fs::path(tmp_res);
}
#endif

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <shlobj.h>
#include <stringapiset.h>
#include <windows.h>
#include <winerror.h>
ludus::fs::path get_known_windows_folder(REFKNOWNFOLDERID folder_id,
                                         const char *error_msg) {
  LPWSTR wszPath = NULL;
  HRESULT hr;
  hr = SHGetKnownFolderPath(folderId, KF_FLAG_CREATE, NULL, &wszPath);
  LPWSTR ptr = wszPath;
  if (!SUCCEEDED(hr)) {
    CoTaskMemFree(ptr);
    throw std::runtime_error(errorMsg);
  }
  CoTaskMemFree(ptr);
  return ludus::fs::path(wszPath);
}
std::string get_app_data() {
  return get_known_windows_folder(FOLDERID_RoamingAppData,
                                  "RoamingAppData could not be found");
}

std::string get_app_data_common() {
  return get_known_windows_folder(FOLDERID_ProgramData,
                                  "ProgramData could not be found");
}

std::string get_app_data_local() {
  return get_known_windows_folder(FOLDERID_LocalAppData,
                                  "LocalAppData could not be found");
}
#elif defined(__APPLE__)
#else
void throw_on_relative(const char *env_name, const char *env_value) {
  if (env_value[0] != '/') {
    char buffer[255];
    std::snprintf(
        buffer, sizeof(buffer),
        "Environment \"%s\" does not start with an '/'. XDG specifies that the "
        "value must be absolute. The current value is: \"%s\"",
        env_name, env_value);
    throw std::runtime_error(buffer);
  }
}

ludus::fs::path get_linux_folder_default(const char *env_name,
                                         const char *default_rel_path) {
  const char *env_value = std::getenv(env_name);
  if (env_value) {
    throw_on_relative(env_name, env_value);
    return ludus::fs::path(env_value);
  }
  return ludus::fs::get_home_dir().append(default_rel_path);
}
#endif

ludus::fs::path ludus::fs::get_data_dir() {
#ifdef _WIN32
  return get_app_data();
#elif defined(__APPLE__)
  return get_home_dir().append("/Library/Application Support");
#else
  return get_linux_folder_default("XDG_DATA_HOME", ".local/share");
#endif
}
ludus::fs::path ludus::fs::get_config_dir() {
#ifdef _WIN32
  return get_app_data();
#elif defined(__APPLE__)
  return get_home_dir().append("/Library/Application Support");
#else
  return get_linux_folder_default("XDG_CONFIG_HOME", ".config");
#endif
}
ludus::fs::path ludus::fs::get_cache_dir() {
#ifdef _WIN32
  return get_app_data_local();
#elif defined(__APPLE__)
  return get_home_dir().append("/Library/Caches");
#else
  return get_linux_folder_default("XDG_CACHE_HOME", ".cache");
#endif
}
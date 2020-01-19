#ifndef LUDUS_LOG_HPP_
#define LUDUS_LOG_HPP_

#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>

#ifdef __DEBUG__
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#endif

#include <spdlog/spdlog.h>

#define LUDUS_LOGGER_CALL(logger, level, ...)                                  \
  (logger)->log(spdlog::source_loc{__FILE__, __LINE__, SPDLOG_FUNCTION},       \
                level, __VA_ARGS__)
#define LUDUS_LOGGER_CALL_SOURCE(logger, level, file, line, function, ...)     \
  (logger)->log(spdlog::source_loc(file, line, function), level, __VA_ARGS__)

#define LUDUS_LOGGER_TRACE(logger, ...)                                        \
  LUDUS_LOGGER_CALL(logger, spdlog::level::trace, __VA_ARGS__)
#define LUDUS_LOGGER_DEBUG(logger, ...)                                        \
  LUDUS_LOGGER_CALL(logger, spdlog::level::debug, __VA_ARGS__)
#define LUDUS_LOGGER_INFO(logger, ...)                                         \
  LUDUS_LOGGER_CALL(logger, spdlog::level::info, __VA_ARGS__)
#define LUDUS_LOGGER_WARN(logger, ...)                                         \
  LUDUS_LOGGER_CALL(logger, spdlog::level::warn, __VA_ARGS__)
#define LUDUS_LOGGER_ERROR(logger, ...)                                        \
  LUDUS_LOGGER_CALL(logger, spdlog::level::err, __VA_ARGS__)
#define LUDUS_LOGGER_CRITICAL(logger, ...)                                     \
  LUDUS_LOGGER_CALL(logger, spdlog::level::critical, __VA_ARGS__)
#define LUDUS_LOGGER_FATAL(logger, ...)                                        \
  LUDUS_LOGGER_CALL(logger, spdlog::level::critical, __VA_ARGS__)

#define LUDUS_LOGGER_SOURCE_TRACE(logger, file, line, function, ...)           \
  LUDUS_LOGGER_SOURCE_CALL(logger, spdlog::level::trace, __VA_ARGS__)
#define LUDUS_LOGGER_SOURCE_DEBUG(logger, file, line, function, ...)           \
  LUDUS_LOGGER_SOURCE_CALL(logger, spdlog::level::debug, __VA_ARGS__)
#define LUDUS_LOGGER_SOURCE_INFO(logger, file, line, function, ...)            \
  LUDUS_LOGGER_SOURCE_CALL(logger, spdlog::level::info, __VA_ARGS__)
#define LUDUS_LOGGER_SOURCE_WARN(logger, file, line, function, ...)            \
  LUDUS_LOGGER_SOURCE_CALL(logger, spdlog::level::warn, __VA_ARGS__)
#define LUDUS_LOGGER_SOURCE_ERROR(logger, file, line, function, ...)           \
  LUDUS_LOGGER_SOURCE_CALL(logger, spdlog::level::err, __VA_ARGS__)
#define LUDUS_LOGGER_SOURCE_CRITICAL(logger, file, line, function, ...)        \
  LUDUS_LOGGER_SOURCE_CALL(logger, spdlog::level::critical, __VA_ARGS__)
#define LUDUS_LOGGER_SOURCE_FATAL(logger, file, line, function, ...)           \
  LUDUS_LOGGER_SOURCE_CALL(logger, spdlog::level::critical, __VA_ARGS__)

#define LUDUS_CORE_TRACE(...)                                                  \
  LUDUS_LOGGER_TRACE(ludus::logger::get_core(), __VA_ARGS__)
#define LUDUS_CLIENT_TRACE(...)                                                \
  LUDUS_LOGGER_TRACE(ludus::logger::get_client(), __VA_ARGS__)
#define LUDUS_CORE_DEBUG(...)                                                  \
  LUDUS_LOGGER_DEBUG(ludus::logger::get_core(), __VA_ARGS__)
#define LUDUS_CLIENT_DEBUG(...)                                                \
  LUDUS_LOGGER_DEBUG(ludus::logger::get_client(), __VA_ARGS__)
#define LUDUS_CORE_INFO(...)                                                   \
  LUDUS_LOGGER_INFO(ludus::logger::get_core(), __VA_ARGS__)
#define LUDUS_CLIENT_INFO(...)                                                 \
  LUDUS_LOGGER_INFO(ludus::logger::get_client(), __VA_ARGS__)
#define LUDUS_CORE_WARN(...)                                                   \
  LUDUS_LOGGER_WARN(ludus::logger::get_core(), __VA_ARGS__)
#define LUDUS_CLIENT_WARN(...)                                                 \
  LUDUS_LOGGER_WARN(ludus::logger::get_client(), __VA_ARGS__)
#define LUDUS_CORE_ERROR(...)                                                  \
  LUDUS_LOGGER_ERROR(ludus::logger::get_core(), __VA_ARGS__)
#define LUDUS_CLIENT_ERROR(...)                                                \
  LUDUS_LOGGER_ERROR(ludus::logger::get_client(), __VA_ARGS__)
#define LUDUS_CORE_CRITICAL(...)                                               \
  LUDUS_LOGGER_CRITICAL(ludus::logger::get_core(), __VA_ARGS__)
#define LUDUS_CLIENT_CRITICAL(...)                                             \
  LUDUS_LOGGER_CRITICAL(ludus::logger::get_client(), __VA_ARGS__)
#define LUDUS_CORE_FATAL(...)                                                  \
  LUDUS_LOGGER_FATAL(ludus::logger::get_core(), __VA_ARGS__)
#define LUDUS_CLIENT_FATAL(...)                                                \
  LUDUS_LOGGER_FATAL(ludus::logger::get_client(), __VA_ARGS__)

#define LUDUS_CORE_SOURCE_TRACE(file, line, function, ...)                     \
  LUDUS_LOGGER_SOURCE_TRACE(ludus::logger::get_core(), file, line, function,   \
                            __VA_ARGS__)
#define LUDUS_CLIENT_SOURCE_TRACE(file, line, function, ...)                   \
  LUDUS_LOGGER_SOURCE_TRACE(ludus::logger::get_client(), file, line, function, \
                            __VA_ARGS__)
#define LUDUS_CORE_SOURCE_DEBUG(file, line, function, ...)                     \
  LUDUS_LOGGER_SOURCE_DEBUG(ludus::logger::get_core(), file, line, function,   \
                            __VA_ARGS__)
#define LUDUS_CLIENT_SOURCE_DEBUG(file, line, function, ...)                   \
  LUDUS_LOGGER_SOURCE_DEBUG(ludus::logger::get_client(), file, line, function, \
                            __VA_ARGS__)
#define LUDUS_CORE_SOURCE_INFO(file, line, function, ...)                      \
  LUDUS_LOGGER_SOURCE_INFO(ludus::logger::get_core(), file, line, function,    \
                           __VA_ARGS__)
#define LUDUS_CLIENT_SOURCE_INFO(file, line, function, ...)                    \
  LUDUS_LOGGER_SOURCE_INFO(ludus::logger::get_client(), file, line, function,  \
                           __VA_ARGS__)
#define LUDUS_CORE_SOURCE_WARN(file, line, function, ...)                      \
  LUDUS_LOGGER_SOURCE_WARN(ludus::logger::get_core(), file, line, function,    \
                           __VA_ARGS__)
#define LUDUS_CLIENT_SOURCE_WARN(file, line, function, ...)                    \
  LUDUS_LOGGER_SOURCE_WARN(ludus::logger::get_client(), file, line, function,  \
                           __VA_ARGS__)
#define LUDUS_CORE_SOURCE_ERROR(file, line, function, ...)                     \
  LUDUS_LOGGER_SOURCE_ERROR(ludus::logger::get_core(), file, line, function,   \
                            __VA_ARGS__)
#define LUDUS_CLIENT_SOURCE_ERROR(file, line, function, ...)                   \
  LUDUS_LOGGER_SOURCE_ERROR(ludus::logger::get_client(), file, line, function, \
                            __VA_ARGS__)
#define LUDUS_CORE_SOURCE_CRITICAL(file, line, function, ...)                  \
  LUDUS_LOGGER_SOURCE_CRITICAL(ludus::logger::get_core(), file, line,          \
                               function, __VA_ARGS__)
#define LUDUS_CLIENT_SOURCE_CRITICAL(file, line, function, ...)                \
  LUDUS_LOGGER_SOURCE_CRITICAL(ludus::logger::get_client(), file, line,        \
                               function, __VA_ARGS__)
#define LUDUS_CORE_SOURCE_FATAL(file, line, function, ...)                     \
  LUDUS_LOGGER_SOURCE_FATAL(ludus::logger::get_core(), file, line, function,   \
                            __VA_ARGS__)
#define LUDUS_CLIENT_SOURCE_FATAL(file, line, function, ...)                   \
  LUDUS_LOGGER_SOURCE_FATAL(ludus::logger::get_client(), file, line, function, \
                            __VA_ARGS__)

#define LTRACE(...) LUDUS_CORE_TRACE(__VA_ARGS__)
#define LDEBUG(...) LUDUS_CORE_DEBUG(__VA_ARGS__)
#define LINFO(...) LUDUS_CORE_INFO(__VA_ARGS__)
#define LWARN(...) LUDUS_CORE_WARN(__VA_ARGS__)
#define LERROR(...) LUDUS_CORE_ERROR(__VA_ARGS__)
#define LCRITICAL(...) LUDUS_CORE_CRITICAL(__VA_ARGS__)
#define LFATAL(...) LUDUS_CORE_FATAL(__VA_ARGS__)

#define LCTRACE(...) LUDUS_CLIENT_TRACE(__VA_ARGS__)
#define LCDEBUG(...) LUDUS_CLIENT_DEBUG(__VA_ARGS__)
#define LCINFO(...) LUDUS_CLIENT_INFO(__VA_ARGS__)
#define LCWARN(...) LUDUS_CLIENT_WARN(__VA_ARGS__)
#define LCERROR(...) LUDUS_CLIENT_ERROR(__VA_ARGS__)
#define LCCRITICAL(...) LUDUS_CLIENT_CRITICAL(__VA_ARGS__)
#define LCFATAL(...) LUDUS_CLIENT_FATAL(__VA_ARGS__)

#define LSTRACE(file, line, function, ...)                                     \
  LUDUS_CORE_SOURCE_TRACE(file, line, function, __VA_ARGS__)
#define LSDEBUG(file, line, function, ...)                                     \
  LUDUS_CORE_SOURCE_DEBUG(file, line, function, __VA_ARGS__)
#define LSINFO(file, line, function, ...)                                      \
  LUDUS_CORE_SOURCE_INFO(file, line, function, __VA_ARGS__)
#define LSWARN(file, line, function, ...)                                      \
  LUDUS_CORE_SOURCE_WARN(file, line, function, __VA_ARGS__)
#define LSERROR(file, line, function, ...)                                     \
  LUDUS_CORE_SOURCE_ERROR(file, line, function, __VA_ARGS__)
#define LSCRITICAL(file, line, function, ...)                                  \
  LUDUS_CORE_SOURCE_CRITICAL(file, line, function, __VA_ARGS__)
#define LSFATAL(file, line, function, ...)                                     \
  LUDUS_CORE_SOURCE_FATAL(file, line, function, __VA_ARGS__)

#define LCSTRACE(file, line, function, ...)                                    \
  LUDUS_CLIENT_SOURCE_TRACE(file, line, function, __VA_ARGS__)
#define LCSDEBUG(file, line, function, ...)                                    \
  LUDUS_CLIENT_SOURCE_DEBUG(file, line, function, __VA_ARGS__)
#define LCSINFO(file, line, function, ...)                                     \
  LUDUS_CLIENT_SOURCE_INFO(file, line, function, __VA_ARGS__)
#define LCSWARN(file, line, function, ...)                                     \
  LUDUS_CLIENT_SOURCE_WARN(file, line, function, __VA_ARGS__)
#define LCSERROR(file, line, function, ...)                                    \
  LUDUS_CLIENT_SOURCE_ERROR(file, line, function, __VA_ARGS__)
#define LCSCRITICAL(file, line, function, ...)                                 \
  LUDUS_CLIENT_SOURCE_CRITICAL(file, line, function, __VA_ARGS__)
#define LCSFATAL(file, line, function, ...)                                    \
  LUDUS_CLIENT_SOURCE_FATAL(file, line, function, __VA_ARGS__)

namespace ludus {
namespace logger {
  enum LogLevel {
    TRACE = spdlog::level::trace,
    DEBUG = spdlog::level::debug,
    INFO = spdlog::level::info,
    WARN = spdlog::level::warn,
    ERR = spdlog::level::warn,
    CRITICAL = spdlog::level::critical,
    OFF = spdlog::level::off,
  };

#ifdef __DEBUG__
  bool initalize_core_logger(const LogLevel &console_level = DEBUG,
                             const LogLevel &file_level = TRACE);
  bool initalize_logger(const std::string &name,
                        const LogLevel &console_level = DEBUG,
                        const LogLevel &file_level = TRACE);
#else
  bool initalize_core_logger(const LogLevel &console_level = OFF,
                             const LogLevel &file_lavel = INFO);
  bool initalize_logger(const std::string &name,
                        const LogLevel &console_level = OFF,
                        const LogLevel &file_lavel = INFO);
#endif
  bool terminate_logger(const std::string &name);

  std::shared_ptr<spdlog::logger> get_core();
  std::shared_ptr<spdlog::logger> get_client();

  namespace core {
    template <typename... _ARGS>
    inline void trace(std::string fmt, const _ARGS &... args) {
      get_core()->trace(fmt, args...);
    }
    template <typename... _ARGS>
    inline void debug(std::string fmt, const _ARGS &... args) {
      get_core()->debug(fmt, args...);
    }
    template <typename... _ARGS>
    inline void info(std::string fmt, const _ARGS &... args) {
      get_core()->info(fmt, args...);
    }
    template <typename... _ARGS>
    inline void warn(std::string fmt, const _ARGS &... args) {
      get_core()->warn(fmt, args...);
    }
    template <typename... _ARGS>
    inline void error(std::string fmt, const _ARGS &... args) {
      get_core()->error(fmt, args...);
    }
    template <typename... _ARGS>
    inline void critical(std::string fmt, const _ARGS &... args) {
      get_core()->info(fmt, args...);
    }
  } // namespace core
  namespace client {
    template <typename... _ARGS>
    inline void trace(std::string fmt, const _ARGS &... args) {
      get_client()->trace(fmt, args...);
    }
    template <typename... _ARGS>
    inline void debug(std::string fmt, const _ARGS &... args) {
      get_client()->debug(fmt, args...);
    }
    template <typename... _ARGS>
    inline void info(std::string fmt, const _ARGS &... args) {
      get_client()->info(fmt, args...);
    }
    template <typename... _ARGS>
    inline void warn(std::string fmt, const _ARGS &... args) {
      get_client()->warn(fmt, args...);
    }
    template <typename... _ARGS>
    inline void error(std::string fmt, const _ARGS &... args) {
      get_client()->error(fmt, args...);
    }
    template <typename... _ARGS>
    inline void critical(std::string fmt, const _ARGS &... args) {
      get_client()->info(fmt, args...);
    }
  } // namespace client
} // namespace logger
} // namespace ludus

#endif // LUDUS_LOG_HPP_

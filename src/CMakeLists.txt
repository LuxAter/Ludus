set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${LUDUS_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LUDUS_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LUDUS_BINARY_DIR})

# ##############################################################################
# SOURCE FILES
# ##############################################################################
set(SOURCES main.cpp log.cpp yaml.cpp fs.cpp)
configure_file("${LUDUS_SOURCE_DIR}/src/version.hpp.in"
               "${LUDUS_SOURCE_DIR}/src/version.hpp")

# ##############################################################################
# STATIC TARGET
# ##############################################################################
add_executable(ludus ${SOURCES})
target_include_directories(ludus
                            PUBLIC ${SPECULA_SOURCE_DIR}/include)

set_target_properties(
 ludus 
  PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS OFF)
target_link_libraries(ludus spdlog yaml-cpp ghc_filesystem)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_link_libraries(ludus)
endif()
install(TARGETS ludus RUNTIME DESTINATION bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${LUDUS_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LUDUS_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LUDUS_BINARY_DIR})

# ##############################################################################
# SOURCE FILES
# ##############################################################################
set(SOURCES main.cpp)
configure_file("${LUDUS_SOURCE_DIR}/src/version.hpp.in"
               "${LUDUS_SOURCE_DIR}/src/version.hpp")

# ##############################################################################
# STATIC TARGET
# ##############################################################################
add_executable(specula ${SOURCES})
target_include_directories(specula
                            PUBLIC ${SPECULA_SOURCE_DIR}/include)

set_target_properties(
  specula 
  PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS OFF)
target_link_libraries(specula spdlog)
install(TARGETS specula RUNTIME DESTINATION lib)
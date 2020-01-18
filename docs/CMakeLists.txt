# ##############################################################################
# SOURCE FILES
# ##############################################################################
set(SOURCES "docs/main.dox")

foreach(path IN LISTS SOURCES)
  set(DOXYGEN_INPUT "${DOXYGEN_INPUT} \\\n\"${LUDUS_SOURCE_DIR}/${path}\"")
endforeach()
configure_file(Doxyfile.in Doxyfile @ONLY)

# ##############################################################################
# TARGET
# ##############################################################################
add_custom_target(
  docs
  "${DOXYGEN_EXECUTABLE}"
  WORKING_DIRECTORY "${LUDUS_BINARY_DIR}/docs"
  COMMENT "Generating Doxygen documentation"
  VERBATIM)

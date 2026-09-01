include_guard(GLOBAL)

function(add_version_header)
  string(TOUPPER "${CMAKE_PROJECT_NAME}" CMAKE_PROJECT_NAME_UPPERCASE)

  set(VERSION_TEMPLATE_FN "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/../templates/version.h.in")
  set(VERSION_CURRENT_FN "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/../version.current.h")
  set(VERSION_FN "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/../include/version.h")

  configure_file(${VERSION_TEMPLATE_FN} ${VERSION_CURRENT_FN} NEWLINE_STYLE LF)
  execute_process(COMMAND ${CMAKE_COMMAND} -E compare_files 
    ${VERSION_CURRENT_FN} ${VERSION_FN}
    RESULT_VARIABLE VersionChanged
  )
  if(VersionChanged EQUAL 0)
    message(STATUS "Version was NOT changed")
    file(REMOVE ${VERSION_CURRENT_FN})
  elseif(VersionChanged EQUAL 1)
    message(STATUS "Project version changed - updating version.h")
    file(REMOVE ${VERSION_FN})
    file(RENAME ${VERSION_CURRENT_FN} ${VERSION_FN})
  else()
    message(WARNING "Error while comparing version.h files!")
  endif()
endfunction()


function(load_third_party_lib lib_name version)
    set(THIRD_PARTY_DIR ${CMAKE_SOURCE_DIR}/ThirdParty)
    set(LIB_DIR ${THIRD_PARTY_DIR}/${lib_name}-${version})

    if(NOT EXISTS ${LIB_DIR})
        message(FATAL_ERROR "Third party library '${lib_name}-${version}' not found in ${THIRD_PARTY_DIR}")
    endif()

    if(EXISTS ${LIB_DIR}/CMakeLists.txt)
        add_subdirectory(${LIB_DIR})
    elseif(EXISTS ${LIB_DIR}/include)
        include_directories(${LIB_DIR}/include)

        if(EXISTS ${LIB_DIR}/lib)
            link_directories(${LIB_DIR}/lib)
        endif()

        if(EXISTS ${LIB_DIR}/bin)
            set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
            file(GLOB BIN_FILES "${LIB_DIR}/bin/*")
            file(COPY ${BIN_FILES} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
        endif()
    else()
        message(WARNING "No valid library structure found for '${lib_name}-${version}'")
    endif()
endfunction()
include(cmake/get_cpm.cmake)


function(setup_dependency target)
    CPMAddPackage(
            NAME glfw
            GIT_TAG 3.4
            GIT_REPOSITORY https://github.com/glfw/glfw.git
            OPTIONS
            "GLFW_BUILD_EXAMPLES OFF"
            "GLFW_BUILD_TESTS OFF"
            "GLFW_BUILD_DOCS OFF"
            "BUILD_SHARED_LIBS OFF"
    )

    CPMAddPackage(
            NAME spdlog
            GIT_TAG v1.15.0
            GIT_REPOSITORY https://github.com/gabime/spdlog.git
            OPTIONS
            "SPDLOG_BUILD_SHARED OFF"
    )

    CPMAddPackage(
            NAME glm
            GIT_TAG 1.0.1
            GIT_REPOSITORY https://github.com/g-truc/glm.git
            OPTIONS
            "GLM_ENABLE_CXX_20 ON"
            "GLM_ENABLE_LANG_EXTENSIONS OFF"
            #                "GLM_ENABLE_FAST_MATH ON"

    )
    CPMAddPackage(
            NAME abseil_cpp
            GIT_TAG 20240722.0
            GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git

    )

    setup_shaderc(${target})

    target_link_libraries(${target} PRIVATE glfw spdlog glm absl::base)

endfunction()


function(setup_shaderc target)
    include(ExternalProject)
    set(lib_name ${CMAKE_STATIC_LIBRARY_PREFIX}shaderc_shared${CMAKE_STATIC_LIBRARY_SUFFIX})
    set(install_dir ${CMAKE_BINARY_DIR}/external/shaderc_ext/install)

    ExternalProject_Add(shaderc_ext
            GIT_REPOSITORY https://github.com/google/shaderc.git
            GIT_TAG v2024.4
            PREFIX ${CMAKE_BINARY_DIR}/external/shaderc_ext
            CONFIGURE_COMMAND ${PYTHON_EXECUTABLE} <SOURCE_DIR>/utils/git-sync-deps

            COMMAND
            ${CMAKE_COMMAND} -S <SOURCE_DIR> -B <BINARY_DIR>
            -DCMAKE_INSTALL_PREFIX=${install_dir}
            -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
            -DSHADERC_SKIP_TESTS=ON
            -DSHADERC_SKIP_EXAMPLES=ON
            -DSHADERC_SKIP_COPYRIGHT_CHECK=ON
            -DSPIRV_TOOLS_BUILD_STATIC=ON
            -DSHADERC_ENABLE_TESTS=OFF

            BUILD_BYPRODUCTS ${install_dir}/lib/${lib_name} # FUCK NINJA
            BUILD_COMMAND ${CMAKE_COMMAND} --build . --target shaderc
            INSTALL_COMMAND ${CMAKE_COMMAND} --build . --target install
            BUILD_ALWAYS 0
    )
    add_dependencies(${target} shaderc_ext)

    file(MAKE_DIRECTORY ${install_dir}/include)
    add_library(libshaderc STATIC IMPORTED GLOBAL)

    set_target_properties(libshaderc PROPERTIES
            IMPORTED_LOCATION ${install_dir}/lib/${lib_name}
            INTERFACE_INCLUDE_DIRECTORIES ${install_dir}/include
    )

    target_link_libraries(${target} PRIVATE libshaderc)
endfunction()
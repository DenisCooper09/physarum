set(LIBRARIES
        glad
        glfw
)

function(build_libraries)
    foreach (LIBRARY ${LIBRARIES})
        message("================================================================")
        message("[INFO] Processing '${LIBRARY}'...")

        set(LIBRARY_DIRECTORY ${PROJECT_SOURCE_DIR}/libs/${LIBRARY})
        set(LIBRARY_BINARY_DIRECTORY ${PROJECT_BINARY_DIR}/libs/${LIBRARY})

        if (NOT EXISTS ${LIBRARY_DIRECTORY}/CMakeLists.txt)
            message("[ERROR] CMakeLists.txt could not be found for '${LIBRARY}'. Continuing to the next library.")
            continue()
        endif ()

        message("[INFO] Found CMakeLists.txt for '${LIBRARY}'. Building...")
        add_subdirectory(${LIBRARY_DIRECTORY} ${LIBRARY_BINARY_DIRECTORY})

        message("[INFO] Linking...")
        target_link_libraries(physarum PRIVATE ${LIBRARY})
        target_include_directories(physarum PRIVATE ${LIBRARY_DIRECTORY}/include)
    endforeach ()
endfunction()

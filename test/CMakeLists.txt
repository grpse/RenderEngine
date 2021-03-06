project(Test)

add_executable(Test main.cpp)

# SET C++14 STANDARD
set (CMAKE_CXX_STANDARD 14)
if (UNIX)
    add_definitions("-std=c++14")
    add_definitions("-ggdb")
endif(UNIX)

# RENDER ENGINE INCLUDE DIRECTORY
include_directories(${RenderEngine_BINARY_DIR}/exported/include)

# LINK ONLY TO RENDER ENGINE (ALL LIBRARIES LINKED TO RENDER ENGINE ARE STATICALLY LINKED)
target_link_libraries(Test RenderEngine )


# SETUP EXPORT DLL FOR WINDOWS
MESSAGE( STATUS "RenderEngine_SOURCE_DIR:          " ${RenderEngine_SOURCE_DIR})

# COPY ALL CONTENT ONLY ON WINDOWS
#if (WIN32)
    add_custom_command(TARGET Test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:RenderEngine>
        $<TARGET_FILE_DIR:Test>)

    #Copy texture
    add_custom_command(TARGET Test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${Test_SOURCE_DIR}/checkerboard.png
        ${Test_BINARY_DIR}/checkerboard.png)
#endif(WIN32)

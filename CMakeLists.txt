cmake_minimum_required(VERSION 3.22)
project(nullptr_cs2_sdk)
set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SRC
        # source
        "src/*.c" ,
        "src/*.cpp" ,
        "src/**/*.c" ,
        "src/**/*.cpp" ,
        "src/*.cpp"

        # dependencies
        "dependencies/*.c" ,
        "dependencies/*.cpp" ,
        "dependencies/**/*.c" ,
        "dependencies/**/*.cpp" ,
        "dependencies/*.cpp"
        )

add_library(${PROJECT_NAME} MODULE ${SRC})
target_link_libraries(${PROJECT_NAME} "d3d11.lib" "dxgi.lib")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/dependencies")
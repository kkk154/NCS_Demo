cmake_minimum_required(VERSION 3.15)
project(demo)

find_package(OpenCV REQUIRED)
set(CMAKE_CXX_STANDARD 11)

add_executable(demo main.cpp)

target_link_libraries(
        demo
        mvnc
        ${OpenCV_LIBS}
)
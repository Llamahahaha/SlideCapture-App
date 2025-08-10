cmake_minimum_required(VERSION 3.10)
project(SlideCapture)

find_package(OpenCV REQUIRED)

add_executable(SlideCapture main.cpp)
target_link_libraries(SlideCapture ${OpenCV_LIBS})
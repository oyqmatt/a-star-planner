cmake_minimum_required(VERSION 3.22)
project(astar-search)

find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp)

target_include_directories(${PROJECT_NAME}
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
)
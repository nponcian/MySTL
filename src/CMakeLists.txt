cmake_minimum_required(VERSION 3.10.2)
project(mystl_src)

include_directories(.)

# add_subdirectory(Algorithms)
# add_subdirectory(Containers)

file(GLOB mystl_src_cpp
    "*.cpp")

add_executable(mystl_src ${mystl_src_cpp})

# target_link_libraries(mystl_src mystl_src_algorithms)
# target_link_libraries(mystl_src mystl_src_containers)

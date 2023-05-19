cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)
project(coding)
aux_source_directory(src SRC_LIST)
add_executable(coding ${SRC_LIST})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(include)

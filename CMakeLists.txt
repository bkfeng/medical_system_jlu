cmake_minimum_required(VERSION 3.17)
project(medical_system_jlu C)

set(CMAKE_C_STANDARD 99)

aux_source_directory(./src DIR_SRCS)
add_executable(medical_system_jlu ${DIR_SRCS})

include_directories(./include )
cmake_minimum_required(VERSION 3.16)
project(TareaMatematicasDiscretas C)

# Use C99 standard (or change to C11 if you prefer)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add include directory (for struct.h)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Collect source files from src/
file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.c)

# Define the executable
add_executable(matematicas ${SRC_FILES})


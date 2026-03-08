# CMakeList.txt: проект CMake для gdp_forecast; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.

cmake_minimum_required(VERSION 3.12)
set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -allow-unsupported-compiler")
project(gdp_forecast LANGUAGES CXX CUDA)

add_executable (gdp_forecast  "main.cpp" "kernel/neyron.cpp" "kernel/neyron.h" "kernel/OB1.cpp" "kernel/OB1.h" "kernel/file.hpp" "kernel/other.cpp" "kernel/other.h" "kernel/relu.hpp" "neys/ney1s.cpp" "neys/ney1s.h" "neys/ney2s.cpp" "neys/ney2s.h" "neys/ney3s.cpp" "neys/ney3s.h" "neys/ney4s.cpp" "neys/ney4s.h" "neym/ney1m.cpp" "neym/ney1m.h" "neym/ney2m.cpp" "neym/ney2m.h" "neym/ney3m.cpp" "neym/ney3m.h" "neym/ney4m.cpp" "neym/ney4m.h" "kernel/config.h" "kernel/config.cpp" "kernel/nvidia/nvidiadate.cu" "kernel/nvidia/nvidiadate.h" "kernel/nvidia/cuda/nvidiac.h" "kernel/nvidia/cuda/nvidiac.cu")


  set_property(TARGET gdp_forecast PROPERTY CXX_STANDARD 20)
  target_include_directories(gdp_forecast PRIVATE ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES})
  set_target_properties(gdp_forecast PROPERTIES CUDA_ARCHITECTURES native)

set_property(TARGET gdp_forecast PROPERTY CXX_STANDARD 20)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.

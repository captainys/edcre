enable_testing()

project(edcre)
add_executable(edcre edcre.cpp)

add_executable(fc fc.cpp)

add_executable(break break.cpp)


add_test(
NAME break_file
COMMAND break ${CMAKE_CURRENT_SOURCE_DIR}/ctest/TSUGARU_OS.mdf ${CMAKE_BINARY_DIR}/intentionally_broken.mdf)

add_test(
NAME verify_break
COMMAND fc -i ${CMAKE_CURRENT_SOURCE_DIR}/ctest/TSUGARU_OS.mdf ${CMAKE_BINARY_DIR}/intentionally_broken.mdf)

add_test(
NAME repair
COMMAND edcre ${CMAKE_BINARY_DIR}/intentionally_broken.mdf)

add_test(
NAME verify_repair
COMMAND fc ${CMAKE_CURRENT_SOURCE_DIR}/ctest/TSUGARU_OS.mdf ${CMAKE_BINARY_DIR}/intentionally_broken.mdf)

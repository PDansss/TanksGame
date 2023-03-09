# CMakeList.txt: проект CMake для TanksGame; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
project ("TanksGame")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (TanksGame "src/Main.cpp" "include/TanksGame.h"  "src/Drow.cpp" "include/Drow.h" "src/Player.cpp"  "include/Player.h" "src/Missile.cpp"  "include/Missile.h" "src/Enemy.cpp" "include/Enemy.h")

target_link_libraries(TanksGame ${CMAKE_SOURCE_DIR}/library/sfml-system.lib)
target_link_libraries(TanksGame ${CMAKE_SOURCE_DIR}/library/sfml-graphics.lib)
target_link_libraries(TanksGame ${CMAKE_SOURCE_DIR}/library/sfml-window.lib)

include_directories(${CMAKE_SOURCE_DIR}/include)

set_property(TARGET TanksGame PROPERTY CXX_STANDART 17)
set_property(TARGET TanksGame PROPERTY CXX_STANDART 17 REQUIRED on)
# TODO: Добавьте тесты и целевые объекты, если это необходимо.

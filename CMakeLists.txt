cmake_minimum_required(VERSION 3.12)

project(walugen
        VERSION 0.0.3
        LANGUAGES C
        DESCRIPTION "Expanding the possibilities for themes"
        HOMEPAGE_URL "https://github.com/SmaileXM/Walugen")

set(PROJECT_LICENSE "MIT license")
set(FLAGS "-Wall -Wextra")

SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${FLAGS}")

set(PROJECT_BINARY_DIR ../bin)

set(SOURCE 
    src/init.c
    src/base/parser.c
    src/base/backend/pywal.c
    src/base/backend/hellwal.c
    src/base/backend/wallpaper/swww.c
    src/base/backend/wallpaper/swaybg.c
    src/func/def.c
    src/msg/log.c)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

add_executable(walugen ${SOURCE})
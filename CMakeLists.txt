# This CMakeLists file is from https://github.com/seksea/gamesneeze/blob/master/CMakeLists.txt as I don't really understand CMake yet
# Therefore I also needed to copy the version of ImGUI from the repository above as well

cmake_minimum_required(VERSION 3.11.0)
project(csgo-simple-linux-cheat)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -O3 -march=core2 -mtune=native -fvisibility=hidden -flto -ggdb -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -std=c++2a -Wall -Wextra")

set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

set(CMAKE_C_FLAGS_RELEASE "-W -Wall -Wextra -O3 -march=native -mtune=native -s -fvisibility=hidden -flto -fwhole-program -Wl,--strip-all")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} --no-gnu-unique -fno-rtti -std=c++2a")

set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")

file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
list(APPEND SOURCES "${CMAKE_SOURCE_DIR}/src/menu/ImGUI/GL/gl3w.c")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_library(csgo-simple-linux-cheat SHARED ${SOURCES})
target_link_libraries(csgo-simple-linux-cheat dl pthread SDL2 GL)
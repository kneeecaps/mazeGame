cmake_minimum_required(VERSION 3.7)

project(mazeGame)

file(GLOB projectSRC CONFIGURE_DEPENDS "src/*.h" "src/*.cpp" "src/*.o")
set(SDL2_LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2/lib")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(lib/SDL2/include)

add_executable(${PROJECT_NAME} ${projectSRC})

target_link_libraries(${PROJECT_NAME} -lmingw32
  Winmm
  ${SDL2_LIBRARY_DIR}/libSDL2_image.a
  ${SDL2_LIBRARY_DIR}/libSDL2_image.dll.a
  ${SDL2_LIBRARY_DIR}/libSDL2main.a
  ${SDL2_LIBRARY_DIR}/libSDL2.dll.a
)

cmake_minimum_required(VERSION 3.7)

project(mazeGame)

file(GLOB projectSRC CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME} ${projectSRC})

target_link_libraries(${PROJECT_NAME}
  SDL2
  SDL2_image
  SDL2_mixer
  SDL2_ttf
)

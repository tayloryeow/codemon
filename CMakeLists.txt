cmake_minimum_required(VERSION 3.5)
project(codemon)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp player.h game.h game.cpp)

LINK_DIRECTORIES( d:\\Logiciels\\mingw\\lib\\allegro )

add_executable(codemon ${SOURCE_FILES})

INCLUDE_DIRECTORIES( d:\\Logiciels\\mingw\\include\\allegro5 )

TARGET_LINK_LIBRARIES(codemon allegro_acodec allegro_audio allegro_color allegro_dialog
        allegro_image allegro_main allegro_memfile allegro_physfs allegro_primitives
        allegro_ttf allegro_font allegro)
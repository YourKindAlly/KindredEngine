cmake_minimum_required(VERSION 4.0)
project(KindredEngine)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
find_package(SDL3_image REQUIRED CONFIG)

set(CMAKE_CXX_STANDARD 26)

add_executable(
        ${PROJECT_NAME}
        main.cpp
        src/Engine.cpp
        header_files/Engine.h
        src/Object.cpp
        header_files/Object.h
        src/Time.cpp
        header_files/Time.h
        src/Vector2.cpp
        header_files/Vector2.h
        src/Engine.cpp
        src/Viewport.cpp
        header_files/Viewport.h
        src/Transform.cpp
        header_files/Transform.h
        src/objects/Sprite.cpp
        header_files/Sprite.h
        src/GameWindow.cpp
        header_files/GameWindow.h
        src/RenderObject.cpp
        header_files/RenderObject.h
        game/Player.cpp
        game/Player.h
        src/RootObject.cpp
        header_files/RootObject.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)
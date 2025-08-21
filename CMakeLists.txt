cmake_minimum_required(VERSION 4.0)
project(KindredEngine)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
find_package(SDL3_image REQUIRED CONFIG)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
        ${PROJECT_NAME}
        main.cpp
        src/Engine.cpp
        header_files/Engine.h
        src/objects/Object.cpp
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
        src/objects/RenderObject.cpp
        header_files/RenderObject.h
        game/Player.cpp
        game/Player.h
        src/RootObject.cpp
        header_files/RootObject.h
        src/objects/Input.cpp
        header_files/Input.h
        src/objects/CollisionObject.cpp
        header_files/CollisionObject.h
        src/Rect.cpp
        header_files/Rect.h
        src/Shape.cpp
        header_files/Shape.h
        src/objects/CollisionBox.cpp
        header_files/CollisionBox.h
        game/Astroid.cpp
        game/Astroid.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)
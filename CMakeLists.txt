cmake_minimum_required(VERSION 4.0)
project(raylib_ecs_test)

set(CMAKE_CXX_STANDARD 23)

find_package(raylib QUIET)

add_executable(raylib_ecs_test src/main.cpp
        src/ecs/entities/Entity.h
        src/ecs/entities/EntityRegistry.cpp
        src/ecs/entities/EntityRegistry.h
        src/ecs/components/SpriteComponent.cpp
        src/ecs/components/SpriteComponent.h
        src/ecs/components/CollisionComponent.cpp
        src/ecs/components/CollisionComponent.h
        src/ecs/components/TransformComponent.cpp
        src/ecs/components/TransformComponent.h
        src/ecs/components/KeyInputComponent.cpp
        src/ecs/components/KeyInputComponent.h
        src/game/factories/PlayerFactory.cpp
        src/game/factories/PlayerFactory.h
)

if(raylib_FOUND)
    target_link_libraries(raylib_ecs_test PRIVATE raylib)
else()
    find_package(PkgConfig REQUIRED)
    pkg_search_module(RAYLIB REQUIRED raylib)
    target_include_directories(raylib_test PRIVATE ${RAYLIB_INCLUDE_DIRS})
    target_link_libraries(raylib_test PRIVATE ${RAYLIB_LIBRARIES})
endif()
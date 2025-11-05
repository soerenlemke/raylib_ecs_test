cmake_minimum_required(VERSION 4.0)
project(raylib_ecs_test)

set(CMAKE_CXX_STANDARD 23)

find_package(raylib QUIET)

add_executable(raylib_ecs_test src/main.cpp
        src/Entity.h
        src/EntityRegistry.cpp
        src/EntityRegistry.h
        src/components/SpriteComponent.cpp
        src/components/SpriteComponent.h
        src/components/CollisionComponent.cpp
        src/components/CollisionComponent.h
        src/components/TransformComponent.cpp
        src/components/TransformComponent.h
        src/components/KeyInputComponent.cpp
        src/components/KeyInputComponent.h
)

if(raylib_FOUND)
    target_link_libraries(raylib_ecs_test PRIVATE raylib)
else()
    find_package(PkgConfig REQUIRED)
    pkg_search_module(RAYLIB REQUIRED raylib)
    target_include_directories(raylib_test PRIVATE ${RAYLIB_INCLUDE_DIRS})
    target_link_libraries(raylib_test PRIVATE ${RAYLIB_LIBRARIES})
endif()
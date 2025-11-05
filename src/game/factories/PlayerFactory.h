//
// Created by soeren on 05.11.25.
//

#ifndef RAYLIB_ECS_TEST_PLAYERFACTORY_H
#define RAYLIB_ECS_TEST_PLAYERFACTORY_H

namespace ECS {
    class EntityRegistry;
    class Entity;
}

namespace Game {
    class PlayerFactory {
        static ECS::Entity CreatePlayer(ECS::EntityRegistry &registry, float x = 0.0f, float y = 0.0f,
                                        int spriteId = 0);
    };
}


#endif //RAYLIB_ECS_TEST_PLAYERFACTORY_H

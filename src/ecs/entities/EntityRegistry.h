//
// Created by soeren on 05.11.25.
//

#ifndef RAYLIB_ECS_TEST_ENTITYREGISTRY_H
#define RAYLIB_ECS_TEST_ENTITYREGISTRY_H
#include <unordered_map>
#include <vector>

#include "Entity.h"
#include "../components/CollisionComponent.h"
#include "../components/KeyInputComponent.h"
#include "../components/SpriteComponent.h"
#include "../components/TransformComponent.h"

namespace ECS {
    class EntityRegistry {
    public:
        explicit EntityRegistry(int maxEntities = 1000);

        Entity CreateEntity();

        void DestroyEntity(const Entity &entity);

        int GetEntityCount() const;

        int GetMaxEntities() const;

    private:
        int nextId = 1;
        int maxEntities = 1000;

        std::vector<Entity> Entities;

        std::unordered_map<Entity, SpriteComponent> Sprites;
        std::unordered_map<Entity, TransformComponent> Transforms;
        std::unordered_map<Entity, KeyInputComponent> KeyInputs;
        std::unordered_map<Entity, CollisionComponent> Collisions;
    };
}

#endif //RAYLIB_ECS_TEST_ENTITYREGISTRY_H

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

        void AddSprite(const Entity &e, const SpriteComponent &sc);
        SpriteComponent* GetSprite(const Entity &e);
        void RemoveSprite(const Entity &e);

        void AddTransform(const Entity &e, const TransformComponent &tc);
        TransformComponent* GetTransform(const Entity &e);
        void RemoveTransform(const Entity &e);

        void AddKeyInput(const Entity &e, const KeyInputComponent &kc);
        KeyInputComponent* GetKeyInput(const Entity &e);
        void RemoveKeyInput(const Entity &e);

        void AddCollision(const Entity &e, const CollisionComponent &cc);
        CollisionComponent* GetCollision(const Entity &e);
        void RemoveCollision(const Entity &e);

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

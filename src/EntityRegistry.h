//
// Created by soeren on 05.11.25.
//

#ifndef RAYLIB_ECS_TEST_ENTITYREGISTRY_H
#define RAYLIB_ECS_TEST_ENTITYREGISTRY_H
#include <unordered_map>
#include <vector>

#include "Entity.h"
#include "components/CollisionComponent.h"
#include "components/KeyInputComponent.h"
#include "components/SpriteComponent.h"
#include "components/TransformComponent.h"


class EntityRegistry {
public:
    EntityRegistry(const std::unordered_map<Entity, SpriteComponent> &sprites,
                   const std::unordered_map<Entity, TransformComponent> &transforms,
                   const std::unordered_map<Entity, KeyInputComponent> &key_inputs,
                   const std::unordered_map<Entity, CollisionComponent> &collisions, const int max_entities)
        : Sprites(sprites),
          Transforms(transforms),
          KeyInputs(key_inputs),
          Collisions(collisions),
          maxEntities(max_entities) {
    }

    std::vector<Entity> Entities;

    std::unordered_map<Entity, SpriteComponent> Sprites;
    std::unordered_map<Entity, TransformComponent> Transforms;
    std::unordered_map<Entity, KeyInputComponent> KeyInputs;
    std::unordered_map<Entity, CollisionComponent> Collisions;

    void CreateEntity();
    void DestroyEntity(const Entity& entity);

    int GetEntityCount() const {
        return entities;
    }

    int GetMaxEntities() const {
        return maxEntities;
    }

private:
    int entities = 0;
    int maxEntities = 1000;
};


#endif //RAYLIB_ECS_TEST_ENTITYREGISTRY_H

//
// Created by soeren on 05.11.25.
//

#include "EntityRegistry.h"


ECS::EntityRegistry::EntityRegistry(int maxEntities)
    : maxEntities(maxEntities) {
}

ECS::Entity ECS::EntityRegistry::CreateEntity() {
    Entity e(nextId++);
    Entities.emplace_back(e);
    return e;
}

void ECS::EntityRegistry::DestroyEntity(const Entity &entity) {
    std::erase(Entities, entity);
    Sprites.erase(entity);
    Transforms.erase(entity);
    KeyInputs.erase(entity);
    Collisions.erase(entity);
}

int ECS::EntityRegistry::GetEntityCount() const {
    return static_cast<int>(Entities.size());
}

int ECS::EntityRegistry::GetMaxEntities() const {
    return maxEntities;
}

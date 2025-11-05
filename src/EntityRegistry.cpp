//
// Created by soeren on 05.11.25.
//

#include "EntityRegistry.h"


EntityRegistry::EntityRegistry(int maxEntities)
    : maxEntities(maxEntities) {
}

Entity EntityRegistry::CreateEntity() {
    Entity e(nextId++);
    Entities.emplace_back(e);
    return e;
}

void EntityRegistry::DestroyEntity(const Entity &entity) {
    std::erase(Entities, entity);
    Sprites.erase(entity);
    Transforms.erase(entity);
    KeyInputs.erase(entity);
    Collisions.erase(entity);
}

int EntityRegistry::GetEntityCount() const {
    return static_cast<int>(Entities.size());
}

int EntityRegistry::GetMaxEntities() const {
    return maxEntities;
}

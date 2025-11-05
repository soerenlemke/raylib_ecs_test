//
// Created by soeren on 05.11.25.
//

#include "EntityRegistry.h"


void EntityRegistry::CreateEntity() {
    auto entity = Entity(entities + 1);
    Entities.emplace_back(entity);
    entities++;
}

void EntityRegistry::DestroyEntity(const Entity &entity) {
    std::erase(Entities, entity);
}

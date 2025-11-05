//
// Created by soeren on 05.11.25.
//

#include "EntityRegistry.h"

namespace ECS {
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

    void EntityRegistry::AddSprite(const Entity &e, const SpriteComponent &sc) {
        Sprites[e] = sc;
    }

    SpriteComponent *EntityRegistry::GetSprite(const Entity &e) {
        const auto iterator = Sprites.find(e);
        if (iterator == Sprites.end()) return nullptr;
        return &iterator->second;
    }

    void EntityRegistry::RemoveSprite(const Entity &e) {
        Sprites.erase(e);
    }

    void EntityRegistry::AddTransform(const Entity &e, const TransformComponent &tc) {
        Transforms[e] = tc;
    }

    TransformComponent *EntityRegistry::GetTransform(const Entity &e) {
        const auto iterator = Transforms.find(e);
        if (iterator == Transforms.end()) return nullptr;
        return &iterator->second;
    }

    void EntityRegistry::RemoveTransform(const Entity &e) {
        Transforms.erase(e);
    }

    void EntityRegistry::AddKeyInput(const Entity &e, const KeyInputComponent &kc) {
        KeyInputs[e] = kc;
    }

    KeyInputComponent *EntityRegistry::GetKeyInput(const Entity &e) {
        const auto iterator = KeyInputs.find(e);
        if (iterator == KeyInputs.end()) return nullptr;
        return &iterator->second;
    }

    void EntityRegistry::RemoveKeyInput(const Entity &e) {
        KeyInputs.erase(e);
    }

    void EntityRegistry::AddCollision(const Entity &e, const CollisionComponent &cc) {
        Collisions[e] = cc;
    }

    CollisionComponent *EntityRegistry::GetCollision(const Entity &e) {
        const auto iterator = Collisions.find(e);
        if (iterator == Collisions.end()) return nullptr;
        return &iterator->second;
    }

    void EntityRegistry::RemoveCollision(const Entity &e) {
        Collisions.erase(e);
    }

    int EntityRegistry::GetEntityCount() const {
        return static_cast<int>(Entities.size());
    }

    int EntityRegistry::GetMaxEntities() const {
        return maxEntities;
    }
}

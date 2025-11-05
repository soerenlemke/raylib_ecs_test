//
// Created by soeren on 05.11.25.
//

#include "PlayerFactory.h"
#include "../../ecs/entities/Entity.h"
#include "../../ecs/entities/EntityRegistry.h"
#include "../../ecs/components/TransformComponent.h"

namespace Game {
    ECS::Entity PlayerFactory::CreatePlayer(ECS::EntityRegistry &registry, float x, float y, int spriteId) {
        const auto e = registry.CreateEntity();

        const auto tc = ECS::TransformComponent(x, y, 0, 0);
        registry.AddTransform(e, tc);

        constexpr auto sc = ECS::SpriteComponent();
        registry.AddSprite(e, sc);

        constexpr auto cc = ECS::CollisionComponent();
        registry.AddCollision(e, cc);

        constexpr auto kc = ECS::KeyInputComponent();
        registry.AddKeyInput(e, kc);

        return e;
    }
}

//
// Created by soeren on 05.11.25.
//

#ifndef RAYLIB_ECS_TEST_ENTITY_H
#define RAYLIB_ECS_TEST_ENTITY_H
#include <cstdint>
#include <functional>

namespace ECS {
    class Entity {
    public:
        explicit Entity(const uint32_t id)
            : id(id) {
        }

        bool operator==(const Entity &other) const {
            return id == other.id;
        }

        [[nodiscard]] uint32_t GetId() const noexcept {
            return id;
        }

    private:
        uint32_t id{};
    };
}

template<>
struct std::hash<ECS::Entity> {
    size_t operator()(const ECS::Entity &e) const noexcept {
        return std::hash<uint32_t>()(e.GetId());
    }
};

#endif //RAYLIB_ECS_TEST_ENTITY_H
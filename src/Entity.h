//
// Created by soeren on 05.11.25.
//

#ifndef RAYLIB_ECS_TEST_ENTITY_H
#define RAYLIB_ECS_TEST_ENTITY_H
#include <cstdint>


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

// Hash specialization so `Entity` can be used as a key in `std::unordered_map`
template<>
struct std::hash<Entity> {
    size_t operator()(const Entity &e) const noexcept {
        return std::hash<uint32_t>()(e.GetId());
    }
};

#endif //RAYLIB_ECS_TEST_ENTITY_H

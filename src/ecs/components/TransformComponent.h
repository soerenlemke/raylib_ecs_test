//
// Created by soeren on 05.11.25.
//

#ifndef RAYLIB_ECS_TEST_TRANSFORMCOMPONENT_H
#define RAYLIB_ECS_TEST_TRANSFORMCOMPONENT_H

namespace ECS {
    class TransformComponent {
    public:
        TransformComponent() = default;

        float PosX = 0.0f;
        float PosY = 0.0f;
        float VelX = 0.0f;
        float VelY = 0.0f;
    };
}


#endif //RAYLIB_ECS_TEST_TRANSFORMCOMPONENT_H

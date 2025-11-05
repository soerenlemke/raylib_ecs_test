//
// Created by soeren on 05.11.25.
//

#ifndef RAYLIB_ECS_TEST_TRANSFORMCOMPONENT_H
#define RAYLIB_ECS_TEST_TRANSFORMCOMPONENT_H

namespace ECS {
    class TransformComponent {
    public:
        TransformComponent(float pos_x, float pos_y, float vel_x, float vel_y)
            : Pos_X(pos_x),
              Pos_Y(pos_y),
              Vel_X(vel_x),
              Vel_Y(vel_y) {
        }

        float Pos_X = 0.0f;
        float Pos_Y = 0.0f;
        float Vel_X = 0.0f;
        float Vel_Y = 0.0f;
    };
}


#endif //RAYLIB_ECS_TEST_TRANSFORMCOMPONENT_H

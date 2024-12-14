//
// Created by DanceEngine on 2024/12/10.
//

#include "App.h"

#include "GLFW/glfw3.h"

float App::GetDeltaTime() {
    return static_cast<float>(glfwGetTime());
}

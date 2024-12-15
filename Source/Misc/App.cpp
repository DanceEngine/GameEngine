//
// Created by DanceEngine on 2024/12/10.
//

#include "App.h"

#include "GLFW/glfw3.h"


double App::m_currentTime = 0.0;
double App::m_DeltaTime = 0.0;


float App::GetDeltaTime() {
    return static_cast<float>(glfwGetTime());
}

void App::SetDeltaTime(double time) {
    m_DeltaTime = time;
}

void App::SetCurrentTime(double time) {
    m_currentTime = time;
}

double App::CurrentTime() {
    return m_currentTime;
}

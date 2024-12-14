//
// Created by DanceEngine on 2024/12/10.
//

#include "Renderer.h"
#include "Window.h"



Renderer & Renderer::Get() {
    static Renderer singleton{};
    return singleton;
}

void Renderer::Init(Window *window) {
    this->window = window;
}

void Renderer::BeginFrame() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::EndFrame() {
    glfwSwapBuffers(window->GetNativeWindow());
    glfwPollEvents();
}


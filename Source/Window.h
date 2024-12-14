//
// Created by DanceEngine on 2024/12/10.
//

#ifndef WINDOW_H
#define WINDOW_H
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class GLFWwindow;

class Window {
public:
    void Init();

    static Window &GetWindow();

    static void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    }

    [[nodiscard]] GLFWwindow *GetNativeWindow() const;

    bool WindowShouldClose() const;

    void Destroy() const;

private:
    GLFWwindow *window = nullptr;
};


#endif //WINDOW_H

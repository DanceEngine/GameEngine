//
// Created by DanceEngine on 2024/12/10.
//

#include "Window.h"

#include "Base.h"


void Window::Init() {

    window = glfwCreateWindow(1024, 768, "Hello World", nullptr, nullptr);
    if (!window) {
        RequestExit("failed to create window");
        return;
    }

    glfwMakeContextCurrent(window);
    // 设置窗口用户指针和回调
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, KeyCallback);

}

Window & Window::GetWindow() {
    static Window window;
    return window;
}

GLFWwindow *Window::GetNativeWindow() const {
    return window;
}

bool Window::WindowShouldClose() const {
    return glfwWindowShouldClose(window);
}

void Window::Destroy() const {
    glfwDestroyWindow(window);
}

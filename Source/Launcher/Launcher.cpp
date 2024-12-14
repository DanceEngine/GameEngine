//
// Created by DanceEngine on 2024/12/10.
//

#include "Launcher.h"

#include <iostream>


#include "Base.h"
#include "EngineLoop.h"
#include "Window.h"

#include "GLFW/glfw3.h"

EngineLoop GEngineLoop;

void PreInit() {
    GEngineLoop.PreInit();
}

void Init() {
    GEngineLoop.Init();
}

void EngineTick() {
    GEngineLoop.Tick();
}

void LaunchWindowsStartup(const char *cmdline) {
    if (!glfwInit()) {
        RequestExit("failed to initialize glfw");
        return;
    };
    // 设置OpenGL版本为4.5
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Window::GetWindow().Init();

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        RequestExit("Failed to initialize GLAD");
        return;
    }

    struct AppGuard {
        ~AppGuard() {
            std::cout << "Destroying window" << std::endl;
            GEngineLoop.Exit();
            Window::GetWindow().Destroy();
            glfwTerminate();
        }
    } _guard;

    try {
        GuardedMain(cmdline);
    } catch (std::exception &e) {
        std::cout << "Exception occured: " << e.what() << std::endl;
    }
}


void GuardedMain(const char *cmdline) {
    PreInit();

    Init();

    while (!ShouldExit()) {
        EngineTick();
    }
}

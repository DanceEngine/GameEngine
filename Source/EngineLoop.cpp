//
// Created by DanceEngine on 2024/12/10.
//

#include "EngineLoop.h"

#include "App.h"
#include "Base.h"
#include "Renderer.h"
#include "Window.h"


void EngineLoop::PreInit() {
    m_engine = std::make_unique<Engine>();
}

void EngineLoop::Init() {
    m_engine->Init();
    Renderer::Get().Init(&Window::GetWindow());
}

void EngineLoop::Tick() {
    // todo: 1. 计算DeltaTime
    if (Window::GetWindow().WindowShouldClose()) {
        RequestExit("window closed");
    }

    // ==== Begin Frame ====
    Renderer::Get().BeginFrame();

    m_engine->Tick(App::GetDeltaTime());

    // ==== End Frame ====
    Renderer::Get().EndFrame();
}

void EngineLoop::Exit() {
    m_engine.reset();
}



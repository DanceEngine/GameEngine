//
// Created by DanceEngine on 2024/12/10.
//

#ifndef ENGINELOOP_H
#define ENGINELOOP_H
#include <memory>

#include "Engine.h"


class Window;

class EngineLoop {
public:
    void PreInit();

    void Init();

    void Tick();

    void Exit();

private:
    std::unique_ptr<Engine> m_engine;
};



#endif //ENGINELOOP_H

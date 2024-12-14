//
// Created by DanceEngine on 2024/12/10.
//

#ifndef LAUNCHER_H
#define LAUNCHER_H


#include "glad/glad.h"


void PreInit();

void Init();

void EngineTick();

void LaunchWindowsStartup(const char* cmdline);

void GuardedMain(const char* cmdline);




#endif //LAUNCHER_H

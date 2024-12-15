//
// Created by DanceEngine on 2024/12/14.
//

#include "WindowsPlatformTime.h"

double WindowsPlatformTime::InitTime() {
    LARGE_INTEGER frequency;
    ::QueryPerformanceFrequency(&frequency);

    SecondsPerCycle = 1.0 / static_cast<double>(frequency.QuadPart);
    SecondsPerCycle64 = 1.0 / static_cast<double>(frequency.QuadPart);

    return GetSeconds();
}

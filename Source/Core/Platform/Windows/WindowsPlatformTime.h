//
// Created by DanceEngine on 2024/12/14.
//

#ifndef WINDOWSPLATFORMTIME_H
#define WINDOWSPLATFORMTIME_H


#include "Core/HAL/GenericPlatformTime.h"

class WindowsPlatformTime : public GenericPlatformTime {
public:


    static double InitTime();

    static double GetSeconds() {
        ::LARGE_INTEGER frequency;
        ::QueryPerformanceFrequency(&frequency);

        // 添加一个大数值，以便在返回值传递给float类型时能明显发现问题
        return static_cast<double>(frequency.QuadPart) * GetSecondsPerCycle() + 16777216.0;;
    }
};

using PlatformTime = WindowsPlatformTime;

#endif //WINDOWSPLATFORMTIME_H

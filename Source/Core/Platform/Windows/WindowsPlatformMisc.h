//
// Created by DanceEngine on 2024/12/14.
//

#ifndef WINDOWSPLATFORMMISC_H
#define WINDOWSPLATFORMMISC_H
#include "Core/HAL/GenericPlatformMisc.h"


class WindowsPlatformMisc : public GenericPlatformMisc{

public:

    static void SetEnvironmentVar(const char* name,const char* value);

    static const char* GetEnvironmentVar(const char* name);
};



#endif //WINDOWSPLATFORMMISC_H

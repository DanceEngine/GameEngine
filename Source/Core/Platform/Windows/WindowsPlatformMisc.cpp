//
// Created by DanceEngine on 2024/12/14.
//

#include "WindowsPlatformMisc.h"

#include "Core/CoreTypes.h"

void WindowsPlatformMisc::SetEnvironmentVar(const char *name, const char *value) {

    // ::SetEnvironmentVariable(name, value);
}

const char * WindowsPlatformMisc::GetEnvironmentVar(const char *name) {


    // ::GetEnvironmentVariableW(name, nullptr, 0);;
    return nullptr;
}

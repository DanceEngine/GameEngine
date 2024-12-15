//
// Created by DanceEngine on 2024/12/14.
//

#ifndef PLATFORM_H
#define PLATFORM_H

#ifdef WIN32
#include <Windows.h>

#include "Core/Platform/Windows/WindowPlatformProcess.h"
#include "Core/Platform/Windows/WindowsPlatformTLS.h"
#include "Core/Platform/Windows/WindowsPlatform.h"
#include "Core/Platform/Windows/WindowsPlatformTime.h"

#endif


#endif //PLATFORM_H

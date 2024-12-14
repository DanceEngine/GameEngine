//
// Created by DanceEngine on 2024/12/14.
//

#ifndef WINDOWPLATFORMPROCESS_H
#define WINDOWPLATFORMPROCESS_H
#include "Source/Core/HAL/GenericPlatformProcess.h"



class WindowPlatformProcess : public GenericPlatformProcess{

public:
    /**
     *
     * 更改线程的处理器亲和性
     * 0001 表示只能在第1个核心上运行
     * 0011 表示可以在第1和第2个核心上运行
     * 1111 表示可以在前4个核心上运行
     * @param AffinityMask 位掩码,用于指定允许该线程在哪些处理器上运行
     */
    static void SetThreadAffinityMask(uint64_t AffinityMask);

    static void SetThreadName(const char* name);

    static Thread* CreateRunnableThread();

    static Event* CreateSyncEvent(bool isManualReset);
    static void ReleaseSyncEvent(Event* event);

    static Event* GetSyncEventFromPool(bool isManualReset);

    static void ReturnSyncEventToPool(Event* event);
};


using PlatformProcess =  WindowPlatformProcess;

#endif //WINDOWPLATFORMPROCESS_H

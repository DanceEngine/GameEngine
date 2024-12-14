//
// Created by DanceEngine on 2024/12/14.
//

#ifndef GENERICPLATFORMPROCESS_H
#define GENERICPLATFORMPROCESS_H
#include <cstdint>

class Event;
class Thread;

class GenericPlatformProcess {

public:
    static void SetThreadAffinityMask(uint64_t AffinityMask);

    static void SetThreadName(const char* name);

    static Thread* CreateRunnableThread();

    static Event* CreateSyncEvent(bool isManualReset);

    static Event* GetSyncEventFromPool(bool isManualReset);

    static void ReturnSyncEventToPool(Event* event);

};



#endif //GENERICPLATFORMPROCESS_H

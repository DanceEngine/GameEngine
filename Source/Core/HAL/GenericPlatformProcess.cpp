//
// Created by DanceEngine on 2024/12/14.
//

#include "GenericPlatformProcess.h"

void GenericPlatformProcess::SetThreadAffinityMask(uint64_t AffinityMask) {
}

void GenericPlatformProcess::SetThreadName(const char *name) {
}

Thread *GenericPlatformProcess::CreateRunnableThread() {
    return nullptr;
}

Event *GenericPlatformProcess::CreateSyncEvent(bool isManualReset) {
    return nullptr;
}

Event *GenericPlatformProcess::GetSyncEventFromPool(bool isManualReset) {
    return nullptr;
}

void GenericPlatformProcess::ReturnSyncEventToPool(Event *event) {
}

//
// Created by DanceEngine on 2024/12/14.
//

#include "WindowPlatformProcess.h"

#include "WindowsEvent.h"
#include "WindowsThread.h"

void WindowPlatformProcess::SetThreadAffinityMask(uint64_t AffinityMask) {


}

void WindowPlatformProcess::SetThreadName(const char *name) {

}

Thread * WindowPlatformProcess::CreateRunnableThread() {
    return new WindowsThread{};
}

Event * WindowPlatformProcess::CreateSyncEvent(bool isManualReset) {

    Event* event= new WindowsEvent{};
    if (!event->Create(isManualReset)) {
        delete event;
        event = nullptr;
    }
    return event;
}

void WindowPlatformProcess::ReleaseSyncEvent(Event *event) {
    event->Reset();
    delete event;
}



Event * WindowPlatformProcess::GetSyncEventFromPool(bool isManualReset) {

    //todo: create
    return CreateSyncEvent(isManualReset);
}

void WindowPlatformProcess::ReturnSyncEventToPool(Event *event) {
    //todo: pool
    ReleaseSyncEvent(event);
}

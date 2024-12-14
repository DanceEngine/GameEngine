//
// Created by DanceEngine on 2024/12/14.
//

#include "Thread.h"

#include "Base.h"
#include "ThreadManager.h"
#include "Core/HAL/Platform.h"


uint32_t Thread::TlsSlot = GetTlsSlot();


Thread::Thread() : m_ThreadAffinityMask(0xFFFFFFFFFFFFFFFF) {
}

Thread::~Thread() {
    if (!ShouldExit()) {
        ThreadManager::Get().RemoveThread(m_ThreadId);
    }
}

Thread *Thread::CreateThread(Runnable *runnable, const char *threadName, uint32_t stackSize, ThreadPriority priority,
                             uint64_t threadAffinityMask) {
    Thread *thread = PlatformProcess::CreateRunnableThread();
    if (thread) {
        SetupThread(thread, runnable, stackSize, threadName, priority, threadAffinityMask);
    }
    return thread;
}

void Thread::SetTls() {
    //todo:
    PlatformTLS::IsValidTlsSlot(TlsSlot);
    if (PlatformTLS::GetCurrentThreadId() == m_ThreadId) {
        PlatformTLS::SetTLSValue(TlsSlot, this);
    }
}

void Thread::FreeTls() {
    PlatformTLS::SetTLSValue(TlsSlot, nullptr);
}

uint32_t Thread::GetTlsSlot() {
    const uint32_t slot = PlatformTLS::AllocTlsSlot();
    PlatformTLS::IsValidTlsSlot(slot);
    return slot;
}

void Thread::SetupThread(Thread * &thread, Runnable *runnable, uint32_t stackSize, const char *threadName,
                         ThreadPriority priority, uint64_t threadAffinityMask) {
    bool succeed = thread->CreateInternal(runnable, stackSize, threadName, priority, threadAffinityMask);
    if (!succeed) {
        delete thread;
        thread = nullptr;
        return;
    }

    thread->PostCreate(priority);
}

void Thread::PostCreate(ThreadPriority priority) {
}

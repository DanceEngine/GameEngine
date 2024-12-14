//
// Created by DanceEngine on 2024/12/14.
//

#ifndef WINDOWSTHREAD_H
#define WINDOWSTHREAD_H

#include "Core/CoreMinimal.h"
#include "Core/HAL/Thread/Thread.h"
#include "Core/HAL/Thread/ThreadManager.h"

class WindowsThread: public Thread {


public:

    ~WindowsThread() override;

    void SetPriority(ThreadPriority priority) override;

    void Suspend(bool shouldPause) override;

    bool Kill(bool shouldWait) override;

    void WaitForCompletion() override;

protected:

    static ::DWORD STDCALL ThreadProc(LPVOID pThis) {
        auto* thread = static_cast<WindowsThread *>(pThis);
        ThreadManager::Get().AddThread(thread->m_ThreadId, thread);
        return thread->GuardedRun();
    }

    bool CreateInternal(Runnable *runnable, uint32_t stackSize, const char *threadName, ThreadPriority priority, uint64_t threadAffinityMask) override;

    uint32_t GuardedRun();

    uint32_t Run();

    static int TranslateThreadPriority(ThreadPriority priority);

private:
    HANDLE m_Thread = nullptr;
};

inline void WindowsThread::WaitForCompletion() {
    //todo: mThread
    WaitForSingleObject(m_Thread, INFINITE);
}


#endif //WINDOWSTHREAD_H

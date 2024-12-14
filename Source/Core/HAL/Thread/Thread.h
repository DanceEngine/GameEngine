//
// Created by DanceEngine on 2024/12/14.
//

#ifndef THREAD_H
#define THREAD_H
#include "Runnable.h"


class Event;

enum class ThreadPriority {
    AboveNormal,
    Normal,
    BelowNormal,
    Highest,
    Lowest,
    TimeCritical,
};

class Thread {
public:
    Thread();

    virtual ~Thread();

    virtual void SetPriority(ThreadPriority priority) =0;

    virtual void Suspend(bool shouldPause) = 0;

    virtual bool Kill(bool shouldWait) = 0;

    virtual void WaitForCompletion() = 0;

    static Thread *CreateThread(Runnable *runnable, const char *threadName, uint32_t stackSize = 0,
                                ThreadPriority priority = ThreadPriority::Normal, uint64_t threadAffinityMask = 0);

    [[nodiscard]] uint32_t GetThreadID() const {
        return m_ThreadId;
    }

    [[nodiscard]] const char* GetThreadName() const
    {
        return m_ThreadName;
    }

protected:
    void SetTls();

    void FreeTls();

    static uint32_t GetTlsSlot();

    virtual bool CreateInternal(Runnable *runnable, uint32_t stackSize, const char *threadName, ThreadPriority priority,
                                uint64_t threadAffinityMask) = 0;

private:
    static void SetupThread(Thread *&thread, Runnable *runnable, uint32_t stackSize, const char *threadName,
                            ThreadPriority priority, uint64_t
                            threadAffinityMask);

    void PostCreate(ThreadPriority priority);

protected:
    Runnable *m_Runnable = nullptr;

    uint32_t m_ThreadId = 0;

    uint64_t m_ThreadAffinityMask = 0;

    ThreadPriority m_ThreadPriority = ThreadPriority::Normal;

    const char *m_ThreadName = nullptr;

    Event *m_SyncEventRef = nullptr;

private:
    static uint32_t TlsSlot;
};


#endif //THREAD_H

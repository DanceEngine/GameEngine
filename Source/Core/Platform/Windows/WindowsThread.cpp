//
// Created by DanceEngine on 2024/12/14.
//

#include "WindowsThread.h"

#include "Core/HAL/Event/Event.h"


bool WindowsThread::CreateInternal(Runnable *runnable,uint32_t stackSize,const char*threadName,ThreadPriority priority,uint64_t threadAffinityMask) {

    static bool s_IsInitialized = false;
    if (!s_IsInitialized) {
        ::SetThreadPriority(::GetCurrentThread(), TranslateThreadPriority(ThreadPriority::Normal));
        s_IsInitialized = true;
    }

    m_Runnable = runnable;
    m_ThreadPriority = priority;
    m_ThreadName = threadName;
    m_ThreadAffinityMask =threadAffinityMask;
    m_SyncEventRef = PlatformProcess::GetSyncEventFromPool(true);

    // 以暂停状态创建线程，这样我们可以确保在线程运行之前，ThreadId 已经完成初始化，并且线程管理器已经知道这个线程的存在
    constexpr DWORD flags = STACK_SIZE_PARAM_IS_A_RESERVATION | CREATE_SUSPENDED;
    m_Thread = ::CreateThread(nullptr,stackSize,ThreadProc,this,flags,reinterpret_cast<::DWORD*>(&m_ThreadId));
    if (m_Thread) {
        ::ResumeThread(m_Thread);
        // todo: 等待线程启动并调用Init函数
        m_SyncEventRef->Wait(INFINITE);
        SetPriority(priority);
    }else {
        runnable = nullptr;
    }

    PlatformProcess::ReturnSyncEventToPool(m_SyncEventRef);
    m_SyncEventRef = nullptr;

    return m_Thread != nullptr;
}

uint32_t WindowsThread::GuardedRun() {
    uint32_t exitCode = 0;

    //todo: 亲和性
    PlatformProcess::SetThreadAffinityMask(m_ThreadAffinityMask);

    PlatformProcess::SetThreadName(m_ThreadName);

    //todo: error catch

    exitCode = Run();

    return exitCode;
}

uint32_t WindowsThread::Run() {
    uint32_t ExitCode = 1;
    // todo: check runnable
    if (m_Runnable->Init()) {

        m_SyncEventRef->Trigger();

        // SetTls();

        ExitCode = m_Runnable->Run();

        m_Runnable->Exit();

        // FreeTls();
    }

    return ExitCode;
}

int WindowsThread::TranslateThreadPriority(ThreadPriority priority) {
    switch (priority) {
        case ThreadPriority::AboveNormal: return THREAD_PRIORITY_ABOVE_NORMAL;
        case ThreadPriority::Normal: return THREAD_PRIORITY_NORMAL;
        case ThreadPriority::BelowNormal: return THREAD_PRIORITY_BELOW_NORMAL;
        case ThreadPriority::Highest: return THREAD_PRIORITY_HIGHEST;
        case ThreadPriority::Lowest: return THREAD_PRIORITY_LOWEST;
        case ThreadPriority::TimeCritical: return THREAD_PRIORITY_TIME_CRITICAL;
    }
    return 0;
}

WindowsThread::~WindowsThread() {
   if (m_Thread) {
       WindowsThread::Kill(true);
   }
}

void WindowsThread::SetPriority(ThreadPriority priority) {
    m_ThreadPriority = priority;
    //todo: check thread
    ::SetThreadPriority(m_Thread,TranslateThreadPriority(priority));
}

void WindowsThread::Suspend(bool shouldPause) {
    //todo: check thread
    if (shouldPause) {
        ::SuspendThread(m_Thread);
    }else {
        ::ResumeThread(m_Thread);
    }
}

bool WindowsThread::Kill(bool shouldWait) {
    if (m_Runnable) {
        m_Runnable->Exit();
    }
    if (shouldWait) {
        ::WaitForSingleObject(m_Thread,INFINITE);
    }
    ::CloseHandle(m_Thread);
    m_Thread = nullptr;

    return true;
}

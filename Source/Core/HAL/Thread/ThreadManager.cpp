//
// Created by DanceEngine on 2024/12/14.
//

#include "ThreadManager.h"

ThreadManager::ThreadManager() {
}

ThreadManager::~ThreadManager() {
}

void ThreadManager::AddThread(uint32_t threadId, Thread *thread) {
    //todo: lock
    m_threads[threadId] = thread;
}

void ThreadManager::RemoveThread(uint32_t threadId) {
    //todo: lock
    m_threads.erase(threadId);
}

ThreadManager & ThreadManager::Get() {
    static ThreadManager instance;
    return instance;
}

void ThreadManager::Tick() {

}
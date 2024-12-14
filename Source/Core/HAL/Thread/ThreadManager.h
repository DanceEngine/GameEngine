//
// Created by DanceEngine on 2024/12/14.
//

#ifndef THREADMANAGER_H
#define THREADMANAGER_H
#include <cstdint>
#include <map>


class Thread;

class ThreadManager {


public:
    ThreadManager();
    ~ThreadManager();


    void AddThread(uint32_t threadId, Thread* thread);

    void RemoveThread(uint32_t threadId);


    void Tick();

    static ThreadManager& Get();

private:

    std::map<uint32_t, Thread*> m_threads{};
};



#endif //THREADMANAGER_H

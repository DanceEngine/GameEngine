//
// Created by DanceEngine on 2024/12/22.
//

#ifndef TASKGRAPH_H
#define TASKGRAPH_H
#include <array>


class TaskThread;

struct WorkerThread {

    TaskThread* Worker;
    bool Attached;

    WorkerThread():Worker(nullptr),Attached(false){}
};

class TaskGraph {

protected:
    void Create();

    inline TaskThread& Thread(uint32_t index);

private:
    std::array<WorkerThread,2> m_Workers{};

    uint32_t m_PerThreadIdTlsSlot{PlatformTLS::InvalidTlsSlot};

};



#endif //TASKGRAPH_H

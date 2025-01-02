//
// Created by DanceEngine on 2024/12/22.
//

#ifndef TASKTHREAD_H
#define TASKTHREAD_H
#include "Core/HAL/Thread/Runnable.h"


struct WorkerThread;

class TaskThread:public Runnable {

public:

    void Setup(int id,uint32_t tlsSlot,WorkerThread* worker);

private:
    uint32_t m_TlsSlotId{PlatformTLS::InvalidTlsSlot};

};



#endif //TASKTHREAD_H

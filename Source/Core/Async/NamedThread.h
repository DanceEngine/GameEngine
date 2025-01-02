//
// Created by DanceEngine on 2024/12/22.
//

#ifndef NAMEDTHREAD_H
#define NAMEDTHREAD_H
#include "TaskThread.h"


class NamedThread: public TaskThread {
public:
    uint32_t Run() override;
};



#endif //NAMEDTHREAD_H

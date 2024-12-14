//
// Created by DanceEngine on 2024/12/14.
//

#ifndef RUNNABLE_H
#define RUNNABLE_H
#include <cstdint>


class Runnable {
public:
    virtual bool Init() {
        return true;
    }

    virtual uint32_t Run() = 0;

    virtual void Exit() {
    }

    virtual void Stop() {
    }

    virtual ~Runnable() = default;
};


#endif //RUNNABLE_H

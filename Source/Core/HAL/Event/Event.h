//
// Created by DanceEngine on 2024/12/14.
//

#ifndef EVENT_H
#define EVENT_H
#include <cstdint>


class Event {


public:
    virtual ~Event() =default;

    virtual bool Create(bool isManualReset) = 0;

    virtual bool IsManualReset() = 0;

    virtual void Trigger() = 0;

    virtual void Reset() = 0;

    virtual bool Wait(uint32_t timeout ) = 0;

};



#endif //EVENT_H

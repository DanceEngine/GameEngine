//
// Created by DanceEngine on 2024/12/14.
//

#ifndef WINDOWSEVENT_H
#define WINDOWSEVENT_H

#include "Core/CoreMinimal.h"

#include "Core/HAL/Event/Event.h"


class WindowsEvent : public Event {
public:
    bool Create(bool isManualReset) override;

    bool IsManualReset() override;

    void Trigger() override;

    void Reset() override;

    bool Wait(uint32_t timeout) override;

    ~WindowsEvent() override;

private:
    HANDLE m_event = nullptr;
    bool m_IsManualReset = false;
};


#endif //WINDOWSEVENT_H

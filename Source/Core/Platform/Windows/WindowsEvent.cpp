//
// Created by DanceEngine on 2024/12/14.
//

#include "WindowsEvent.h"

bool WindowsEvent::Create(bool isManualReset) {
    m_event = ::CreateEvent(nullptr, isManualReset, 0, nullptr);
    m_IsManualReset = isManualReset;
    return m_event != nullptr;
}

bool WindowsEvent::IsManualReset() {
    return m_IsManualReset;
}

void WindowsEvent::Trigger() {
    //todo: check event
    ::SetEvent(m_event);
}

void WindowsEvent::Reset() {
    //todo: check event
    ::ResetEvent(m_event);
}

bool WindowsEvent::Wait(uint32_t timeout) {
    return ::WaitForSingleObject(m_event, timeout) == WAIT_OBJECT_0;
}

WindowsEvent::~WindowsEvent() {
    if (m_event) ::CloseHandle(m_event);
}


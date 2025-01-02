//
// Created by DanceEngine on 2024/12/22.
//

#include "TaskGraph.h"

#include "NamedThread.h"

void TaskGraph::Create() {


    m_PerThreadIdTlsSlot = PlatformTLS::AllocTlsSlot();


    for (uint32_t i = 0; i < 2; i++) {
        m_Workers[i].Worker = new NamedThread;
        m_Workers[i].Worker->Setup(1, m_PerThreadIdTlsSlot, &m_Workers[i]);
    }


}

TaskThread & TaskGraph::Thread(uint32_t index) {
    return *m_Workers[index].Worker;
}

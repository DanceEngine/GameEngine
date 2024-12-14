//
// Created by DanceEngine on 2024/12/14.
//

#ifndef WINDOWSPLATFORMTLS_H
#define WINDOWSPLATFORMTLS_H


#include "Core/HAL/GenericPlatformTLS.h"


class WindowsPlatformTLS: public GenericPlatformTLS {


public:
    static inline uint32_t GetCurrentThreadId() {
        return ::GetCurrentThreadId();
    }

    static inline void SetTLSValue(uint32_t slot,void* value) {
        //todo: editor
        // void** ThreadStorage = static_cast<void**>(::FlsGetValue(InvalidTlsSlot));
        // if (ThreadStorage == nullptr) {
        //     // ThreadStorage = Alloc
        // }
        // ThreadStorage[slot] = value;

        ::TlsSetValue(slot, value);
    }

    static uint32_t AllocTlsSlot() {
        return ::TlsAlloc();
    }
};


using PlatformTLS = WindowsPlatformTLS;

#endif //WINDOWSPLATFORMTLS_H

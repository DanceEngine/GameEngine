//
// Created by DanceEngine on 2024/12/14.
//

#ifndef GENERICPLATFORMTLS_H
#define GENERICPLATFORMTLS_H
#include <cstdint>


class GenericPlatformTLS {
protected:
    static constexpr uint32_t InvalidTlsSlot = 0xFFFFFFFF;

public:
    static bool IsValidTlsSlot(uint32_t SlotIndex)
    {
        return SlotIndex != InvalidTlsSlot;
    }
};



#endif //GENERICPLATFORMTLS_H

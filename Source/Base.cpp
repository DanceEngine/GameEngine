//
// Created by DanceEngine on 2024/12/10.
//

#include "Base.h"

#include <iostream>

bool GIsRequestingExit = false;

void RequestExit(const char *reason) {
    GIsRequestingExit = true;
    std::cout << reason << std::endl;
}

bool ShouldExit() {
    return GIsRequestingExit;
}

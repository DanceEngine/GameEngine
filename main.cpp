#include <iostream>

#include "Core/HAL/Thread/Runnable.h"
#include "Core/HAL/Thread/Thread.h"
#include "Launcher/Launcher.h"
#include <spdlog/spdlog.h>

class TestRun: public Runnable {
public:
    uint32_t Run() override {
        SPDLOG_INFO("TestRun");

        SPDLOG_INFO("ThreadID: {}",PlatformTLS::GetCurrentThreadId());

        return 0;
    }

    Thread* CreateThread() {
        return  Thread::CreateThread(this,"TestThread");
    }
};

int main() {

    // LaunchWindowsStartup(nullptr);

    SPDLOG_INFO("Hello World!");
    SPDLOG_INFO("ThreadID: {}",PlatformTLS::GetCurrentThreadId());

    auto* testRun = new TestRun();
    Thread* thread = Thread::CreateThread(testRun,"TestThread");
    thread->WaitForCompletion();
    delete thread;
    delete testRun;
    return 0;
}

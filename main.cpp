#include <iostream>

#include "Core/HAL/Thread/Runnable.h"
#include "Core/HAL/Thread/Thread.h"
#include "Launcher/Launcher.h"
#include <spdlog/spdlog.h>
#include <shaderc/shaderc.hpp>

#include "absl/types/bad_any_cast.h"

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
#include <string>
#include <fstream>
#include <sstream>

enum class FileResult {
    Success = 0,
    EmptyPath,
    FileOpenError,
    EmptyFile,
    ReadError,
    WriteError,
    EmptyData
};

FileResult readTextFile(const std::string& filePath, std::string& outContent) {
    // 参数验证
    if (filePath.empty()) {
        return FileResult::EmptyPath;
    }

    // 打开文件
    std::ifstream file(filePath);
    if (!file.is_open()) {
        return FileResult::FileOpenError;
    }

    // 检查文件大小
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    if (fileSize == 0) {
        return FileResult::EmptyFile;
    }
    file.seekg(0, std::ios::beg);

    std::stringstream buffer;
    buffer << file.rdbuf();

    if (file.fail()) {
        return FileResult::ReadError;
    }

    outContent = buffer.str();
    return FileResult::Success;
}


FileResult writeBinaryFile(const std::string& filePath,
                              const std::vector<uint8_t>& data) {
    if (filePath.empty()) {
        return FileResult::EmptyPath;
    }

    if (data.empty()) {
        return FileResult::EmptyData;
    }

    std::ofstream file(filePath, std::ios::binary | std::ios::trunc);
    if (!file.is_open()) {
        EL_ERROR("Failed to open file {}", filePath);
        return FileResult::FileOpenError;
    }

    file.write(reinterpret_cast<const char*>(data.data()), data.size());

    if (file.fail()) {
        return FileResult::WriteError;
    }

    return FileResult::Success;
}

int main() {

    LaunchWindowsStartup(nullptr);
    //
    // const char* file = R"(D:\Code\Engine\Shader\Test\test_vert.hlsl)";
    // std::string content;
    //
    // readTextFile(file,content);
    //
    //
    //
    // shaderc::Compiler compiler;
    // shaderc::CompileOptions options{};
    // options.SetSourceLanguage(shaderc_source_language_hlsl);
    // auto result = compiler.CompileGlslToSpv(content,shaderc_vertex_shader,"test_vert.hlsl","vert",options);
    // if (result.GetCompilationStatus() == shaderc_compilation_status_compilation_error) {
    //     SPDLOG_ERROR("Compilation Error {}",result.GetErrorMessage());
    // }
    //
    // FileResult res = writeBinaryFile(R"(D:\Code\Engine\Shader\Test\test_vert.spv)",std::vector<uint8_t>(result.begin(),result.end()));
    // EL_INFO("Test Result: {}",static_cast<int>(res));


    // SPDLOG_INFO("Hello World!");
    // SPDLOG_INFO("ThreadID: {}",PlatformTLS::GetCurrentThreadId());

    // auto* testRun = new TestRun();
    // Thread* thread = Thread::CreateThread(testRun,"TestThread");
    // thread->WaitForCompletion();
    // delete thread;
    // delete testRun;
    return 0;
}

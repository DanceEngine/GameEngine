cmake_minimum_required(VERSION 3.30)
project(Engine)

set(CMAKE_CXX_STANDARD 20)

include(cmake/tools.cmake)

load_third_party_lib(glfw 3.4)
load_third_party_lib(glad 4.5)

load_third_party_lib(glm 1.0.1)
load_third_party_lib(spdlog 1.15)

find_package(OpenGL REQUIRED)


add_executable(Engine main.cpp
        Source/Renderer.cpp
        Source/Renderer.h
        Source/EngineLoop.cpp
        Source/EngineLoop.h
        Source/Window.cpp
        Source/Window.h
        Source/Misc/App.cpp
        Source/Misc/App.h
        Source/Engine.cpp
        Source/Engine.h
        Source/Launcher/Launcher.cpp
        Source/Launcher/Launcher.h
        Source/Base.cpp
        Source/Base.h
        Source/Core/Platform/Windows/WindowsThread.cpp
        Source/Core/Platform/Windows/WindowsThread.h
        Source/Core/HAL/Thread/Thread.cpp
        Source/Core/HAL/Thread/Thread.h
        Source/Core/HAL/Thread/Runnable.cpp
        Source/Core/HAL/Thread/Runnable.h
        Source/Core/Platform/Windows/WindowsPlatform.h
        Source/Core/Platform/Windows/WindowPlatformProcess.cpp
        Source/Core/Platform/Windows/WindowPlatformProcess.h
        Source/Core/HAL/GenericPlatformProcess.cpp
        Source/Core/HAL/GenericPlatformProcess.h
        Source/Core/HAL/GenericPlatformTLS.cpp
        Source/Core/HAL/GenericPlatformTLS.h
        Source/Core/Platform/Windows/WindowsPlatformTLS.cpp
        Source/Core/Platform/Windows/WindowsPlatformTLS.h
        Source/Core/HAL/Thread/ThreadManager.cpp
        Source/Core/HAL/Thread/ThreadManager.h
        Source/Core/HAL/Event/Event.cpp
        Source/Core/HAL/Event/Event.h
        Source/Core/Platform/Windows/WindowsEvent.cpp
        Source/Core/Platform/Windows/WindowsEvent.h
        Source/Core/Logging/LogMarco.h
        Source/Core/HAL/Platform.h
        Source/Core/CoreTypes.h
        Source/Core/CoreMinimal.h
        Source/Core/HAL/GenericPlatformTime.cpp
        Source/Core/HAL/GenericPlatformTime.h
        Source/Core/Platform/Windows/WindowsPlatformTime.cpp
        Source/Core/Platform/Windows/WindowsPlatformTime.h
        Source/Core/HAL/GenericPlatformMisc.cpp
        Source/Core/HAL/GenericPlatformMisc.h
        Source/Core/Platform/Windows/WindowsPlatformMisc.cpp
        Source/Core/Platform/Windows/WindowsPlatformMisc.h
)

target_include_directories(Engine PUBLIC Thirdparty/glm-1.0.1)

target_include_directories(Engine PUBLIC Source)

target_precompile_headers(Engine PUBLIC Source/Core/CoreMinimal.h)

target_link_libraries(Engine PUBLIC glfw glad OpenGL::GL glm::glm glm::glm-header-only spdlog::spdlog)


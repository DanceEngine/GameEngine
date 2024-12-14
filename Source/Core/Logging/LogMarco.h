//
// Created by DanceEngine on 2024/12/14.
//

#ifndef LOGMARCO_H
#define LOGMARCO_H


#include <spdlog/spdlog.h>

#define EL_INFO(fmt,...) SPDLOG_INFO(fmt, __VA_ARGS__)
#define EL_WARN(fmt,...) SPDLOG_WARN(fmt, __VA_ARGS__)
#define EL_ERROR(fmt,...) SPDLOG_ERROR(fmt,##__VA_ARGS__)
#define EL_FATAL(fmt,...) SPDLOG_CRITICAL(fmt,##__VA_ARGS__)
#define EL_TRACE(fmt,...) SPDLOG_TRACE(fmt,##__VA_ARGS__)
#define EL_DEBUG(fmt,...) SPDLOG_DEBUG(fmt,##__VA_ARGS__)


#endif //LOGMARCO_H

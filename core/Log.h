#ifndef _LOG_H
#define _LOG_H

#include "com.h"

/*************************************
 *enum define
 ************************************/

typedef enum _LOG_LEVEL{
    LOG_LEVEL_ERROR = 0,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_WARN,
    LOG_LEVEL_INFO,
    LOG_LEVEL_MAX
}LOG_LEVEL;

#define LOG(fmt, ...) printf(fmt, ## __VA_ARGS__)
#define LOGD(str) Log_Output(LOG_LEVEL_DEBUG, str)
#define LOGE(str) Log_Output(LOG_LEVEL_ERROR, str)
#define LOGI(str) Log_Output(LOG_LEVEL_INFO, str)
#define LOGW(str) Log_Output(LOG_LEVEL_WARN, str)

#define LOGT(tag,fmt, ...) printf(tag,fmt, ## __VA_ARGS__)

/*************************************
 *struct define
 ************************************/

/*************************************
 *Functions define
 ************************************/

void Log_Output(LOG_LEVEL level, char* str);

#endif

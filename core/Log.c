#include <stdio.h>
#include <string.h>

#include "Log.h"


void Log_Output(LOG_LEVEL level, char* str)
{
    if(NULL == str) {
        return ;
    }
    switch(level) {
    case LOG_LEVEL_ERROR:
    {
        printf("-----------ERROR-----------\n");
        printf("Error Info:%s\n",str);
        printf("---------------------------\n");
    }
    break;
    case LOG_LEVEL_DEBUG:
    {
        printf("-----------DEBUG-----------\n");
        printf("Debug Info:%s\n",str);
        printf("---------------------------\n");
    }
    break;

    case LOG_LEVEL_WARN:
    {
        printf("-----------WARN-----------\n");
        printf("Warning Info:%s\n",str);
        printf("--------------------------\n");
    }
    break;

    case LOG_LEVEL_INFO:
    {
        printf("-----------INFO-----------\n");
        printf("Info :%s\n",str);
        printf("---------------------------\n");
    }
    break;

    default:
        break;
    }
}




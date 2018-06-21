#ifndef _COM_OS_H
#define _COM_OS_H

#include "com_type.h"

/*************************************
 *enum define
 ************************************/

#define EVENT_DATA_MAX 256



/*************************************
 *struct define
 ************************************/

typedef struct _Event{
    UINT eventId;
    UINT src_module;
    UINT dst_module;
    UBYTE data[EVENT_DATA_MAX];
}Event;


#endif

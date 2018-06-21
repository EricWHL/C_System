#ifndef _EVENT_H
#define _EVENT_H

#include "com.h"
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

/*************************************
 *functions define
 ************************************/

#endif

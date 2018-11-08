#ifndef _MODULE_H
#define _MODULE_H

#include "com.h"

/*************************************
 *enum define
 ************************************/

#define MODULE_NAME_MAX_SIZE 64

/*************************************
 *function pointer define
 ************************************/

typedef void (*CB_FUNC)(Event* event);

/*************************************
 *struct define
 ************************************/

typedef struct _Module{
    UBYTE name[MODULE_NAME_MAX_SIZE];
    UINT id;
    UBYTE priority;
    CB_FUNC ptr;
}Module;


/*************************************
 *functions define
 ************************************/


#endif

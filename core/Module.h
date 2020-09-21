#ifndef _MODULE_H
#define _MODULE_H

#include "com.h"

/*************************************
 *enum define
 ************************************/

#define MODULE_NAME_MAX_SIZE 64

typedef enum _MODULE_TYPE {
    MODULE_TYPE_TASK,
    MODULE_TYPE_CYC,
    MODULE_TYPE_MAX
}MODULE_TYPE;
/*************************************
 *function pointer define
 ************************************/

typedef void (*CB_FUNC)(Event* event);

/*************************************
 *struct define
 ************************************/

typedef struct _ST_Module{
    BYTE name[MODULE_NAME_MAX_SIZE];
    UINT id;
    MODULE_TYPE type;
    UBYTE priority;
    CB_FUNC ptr;
    ULONG stackSize;
    
}ST_Module;


/*************************************
 *functions define
 ************************************/


#endif

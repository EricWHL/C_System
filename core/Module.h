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

typedef struct _ModuleMgr {
    List* module;    
}ModuleMgr;

/*************************************
 *functions define
 ************************************/
void Module_init();
ModuleMgr* Module_Inst();

void Module_run(Event* event);

void Module_register(Module* obj);
void Module_unregister(Module* obj);

#endif

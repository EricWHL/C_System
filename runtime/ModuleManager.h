#ifndef _MODULE_MANAGER_H
#define _MODULE_MANAGER_H

#include "com.h"

typedef struct _ModuleMgr {
    List* module;
    void (*run)(void* event);
}ModuleMgr;

void ModuleMgr_init(void);
void ModuleMgr_Run(void* event);
ModuleMgr* ModuleMgr_Inst(void);

void ModuleMgr_register(Module* obj);
void ModuleMgr_unregister(Module* obj);



#endif 

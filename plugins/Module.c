#include <string.h>

#include "Module.h"
static ModuleMgr s_ModuleMgr;

void IDE_CB_FUNC(Event* event);

void IDE_CB_FUNC(Event* event)
{
    printf("[%s:%d]\n",__FUNCTION__,__LINE__);
}

void Module_init()
{
    Module IDE;
    memset(&IDE, 0x00 , sizeof(Module));

    strcpy(IDE.name,"IDE");
    IDE.id = 0;
    IDE.priority = 0xFF;
    IDE.ptr = IDE_CB_FUNC;

    s_ModuleMgr.module = List_Create();

    List_push(s_ModuleMgr.module,(void*)&IDE,sizeof(Module));
    
}

void Module_run(Event* event)
{
    
}

void Module_register(Module* obj)
{
    
}

void Module_unregister(Module* obj)
{
    
}


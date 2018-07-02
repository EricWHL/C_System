#include <string.h>
#include "Log.h"
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
    ASSERT(s_ModuleMgr.module);

    List_push(s_ModuleMgr.module,(void*)&IDE,sizeof(Module));
    
}

ModuleMgr* Module_Inst()
{
    if(NULL != s_ModuleMgr.module) {
        return &s_ModuleMgr;
    }
    else {
        return NULL;
    }
}

void Module_run(Event* event)
{
    UINT mdcount = 0;
    Module md;
    Node* node = NULL;
    
    memset(&md,0x00,sizeof(Module));
        
    if(NULL == s_ModuleMgr.module) {
        return ;
    }
    mdcount = List_count(s_ModuleMgr.module);
    node = s_ModuleMgr.module->node;
    while (mdcount) {
        memcpy(&md,node->data,sizeof(Module));
        mdcount --;
        md.ptr(event);
        node = node->next;
        if(!node) {
            break;
        }
    }
}

void Module_register(Module* obj)
{
    
}

void Module_unregister(Module* obj)
{
    
}


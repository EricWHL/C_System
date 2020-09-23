#include <stdlib.h>
#include "ModuleManager.h"

static ModuleMgr s_ModuleMgr;

void IDE_CB_FUNC(void* event);

void IDE_CB_FUNC(void* event)
{
    printf("[%s:%d]\n",__FUNCTION__,__LINE__);
}

void ModuleMgr_init()
{
    ST_Module IDE;
    memset(&IDE, 0x00 , sizeof(ST_Module));

    strcpy(IDE.name,"IDE");
    IDE.id = 0;
    IDE.priority = 0xFF;
    IDE.ptr = IDE_CB_FUNC;

    s_ModuleMgr.module = List_Create();
    ASSERT(s_ModuleMgr.module);

    List_push(s_ModuleMgr.module,(void*)&IDE,sizeof(ST_Module));
    s_ModuleMgr.run = ModuleMgr_Run;
    
}

void ModuleMgr_Run(void* event)
{
    UINT mdcount = 0;
    ST_Module md;
    Node* node = NULL;
    
    memset(&md,0x00,sizeof(ST_Module));
        
    if(NULL == s_ModuleMgr.module) {
        return ;
    }
    mdcount = List_count(s_ModuleMgr.module);
    node = s_ModuleMgr.module->node;
    while (mdcount) {
        memcpy(&md,node->data,sizeof(ST_Module));
        mdcount --;
        md.ptr(event);
        node = node->next;
        if(!node) {
            break;
        }
    }
}

ModuleMgr* ModuleMgr_Inst()
{
    if(NULL != s_ModuleMgr.module) {
        return &s_ModuleMgr;
    }
    else {
        return NULL;
    }
}

void ModuleMgr_register(ST_Module* obj)
{
    
}

void ModuleMgr_unregister(ST_Module* obj)
{
    
}

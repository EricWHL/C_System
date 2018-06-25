#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include <pthread.h>

#include "EventLoop.h"

static EventLoop* s_loop = NULL;
static BOOL s_runEnable = FALSE;
static pthread_t el_threadId;

static void* EventLoop_exe(void* data);

void EventLoop_Create()
{
    if(NULL == s_loop) {
        s_loop = (EventLoop*)malloc(sizeof(EventLoop));
        if(NULL == s_loop) {
            return NULL;
        }
    
        s_loop->event = List_Create();
    }
    s_runEnable = TRUE;

    Module_init();
    
}

void EventLoop_Destory()
{
    
}

EventLoop* EventLoop_Inst()
{
    if(NULL == s_loop) {
        EventLoop_Create();
    }
    return s_loop;
}

BOOL EventLoop_IsEmpty()
{
    
}

static void* EventLoop_exe(void* data)
{
    ModuleMgr* mdMgr = Module_Inst();
    Node* node = NULL;
    Event evt;
    UINT evt_count = List_count(s_loop->event);
    
    memset(&evt, 0x00, sizeof(Event));
    printf("[%s:%d]\n",__FUNCTION__,__LINE__);    
    do {

        if(0 == evt_count) {
            Module_run(NULL);
        }
        else {
            while(evt_count) {
                node = List_pop(s_loop->event);
                
                memcpy(&evt, node->data, sizeof(Event));

                Module_run(&evt);
                
                evt_count --;
            }
        }
    }while(0);

}

void EventLoop_Run()
{
    SINT ret = 0;
    printf("[%s:%d]\n",__FUNCTION__,__LINE__);    
    
    ret = pthread_create(&el_threadId, NULL, EventLoop_exe, 0);
    if(0 != ret) {
        printf("pthread_create is Error!!!!!!!!!!!!!!!!!!!!!\n");
    }
    pthread_join(el_threadId,0);
}

EL_OPE_RST EventLoop_Exit()
{
    s_runEnable = FALSE;
    printf("[%s:%d]\n",__FUNCTION__,__LINE__);
    return EL_OPE_RST_OK;
}

EL_OPE_RST EventLoop_SendEvent(Event* event)
{
    
}

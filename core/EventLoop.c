#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include <pthread.h>
#include "Log.h"
#include "EventLoop.h"

/*************************************
 *enum define
 ************************************/


/*************************************
 *struct define
 ************************************/

typedef struct _ST_EL_THREAD_MGR
{
    pthread_t id;
    pthread_mutex_t lock;		/* mutex ensuring exclusive access to eventloop and timer */
    pthread_cond_t th_sig;	/* signaled to eventloop  */

}ST_EL_THREAD_MGR;


static EventLoop* s_loop = NULL;
static BOOL s_runEnable = FALSE;

static ST_EL_THREAD_MGR el_th_mgr;

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
    pthread_mutex_init (&el_th_mgr.lock, NULL);
    pthread_cond_init (&el_th_mgr.th_sig, NULL);

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
    ModuleMgr* mdMgr = ModuleMgr_Inst();
    Node* node = NULL;
    Event evt;
    UINT evt_count = List_count(s_loop->event);
    
    memset(&evt, 0x00, sizeof(Event));
    LOG("[%s:%d]\n",__FUNCTION__,__LINE__);    


    do {
        LOG("[%s:%d]\n",__FUNCTION__,__LINE__);
        pthread_cond_wait (&el_th_mgr.th_sig, &el_th_mgr.lock);
        LOG("[%s:%d]\n",__FUNCTION__,__LINE__);
        LOG("[%s:%d]!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n",__FUNCTION__,__LINE__);
        
        if(0 == evt_count) {
            mdMgr->run(NULL);
        }
        else {
            while(evt_count) {
                node = List_pop(s_loop->event);
                
                memcpy(&evt, node->data, sizeof(Event));

                mdMgr->run(&evt);
                
                evt_count --;
            }
        }
    }while(1);
    LOG("[%d][%s:%d]\n",clock(),__FUNCTION__,__LINE__);    
}

void EventLoop_Run()
{
    SINT ret = 0;
    LOG("[%s:%d]\n",__FUNCTION__,__LINE__);    
    
    ret = pthread_create(&el_th_mgr.id, NULL, EventLoop_exe, 0);
    if(0 != ret) {
        LOG("pthread_create is Error!!!!!!!!!!!!!!!!!!!!!\n");
    }
    Timer_Create(OS_TIME_LOOP_RANGE_10MS);
    pthread_join(el_th_mgr.id,0);
}

EL_OPE_RST EventLoop_Exit()
{
    s_runEnable = FALSE;
    LOG("[%s:%d]\n",__FUNCTION__,__LINE__);
    return EL_OPE_RST_OK;
}

void EventLoop_Wakeup()
{
    LOG("[Time:%d][%s:%d]\n",clock(),__FUNCTION__,__LINE__);    
    pthread_cond_signal (&el_th_mgr.th_sig);
}

EL_OPE_RST EventLoop_SendEvent(Event* event)
{
    
}

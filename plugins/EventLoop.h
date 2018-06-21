#ifndef _EVENT_LOOP_H_
#define _EVENT_LOOP_H_

#include "com.h"

#include "List.h"
/*************************************
 *enum define
 ************************************/

typedef enum _EL_OPE_RST {
    EL_OPE_RST_OK = 0,
    EL_OPE_RST_NG,
    EL_OPE_RST_MAX
}EL_OPE_RST;

/*************************************
 *struct define
 ************************************/

typedef struct _EventLoop {
    List* event;
}EventLoop;

/*************************************
 *Functions define
 ************************************/

EventLoop* EventLoop_Create();
void EventLoop_Destory();

EventLoop* EventLoop_Inst();

BOOL EventLoop_IsEmpty();

EL_OPE_RST EventLoop_Run();
EL_OPE_RST EventLoop_Exit();

EL_OPE_RST EventLoop_SendEvent(Event* event);
#endif

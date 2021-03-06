#ifndef _EVENT_LOOP_H_
#define _EVENT_LOOP_H_

#include "com.h"

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

void EventLoop_Create(void);
void EventLoop_Destory(void);

EventLoop* EventLoop_Inst(void);

BOOL EventLoop_IsEmpty(void);

void EventLoop_Run(void);
EL_OPE_RST EventLoop_Exit(void);

void EventLoop_Wakeup(void);

EL_OPE_RST EventLoop_SendEvent(Event* event);
#endif

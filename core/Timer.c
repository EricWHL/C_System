#include <pthread.h>
#include <time.h>

#include "EventLoop.h"
#include "Timer.h"

/*************************************
 *enum define
 ************************************/

#define TIMEOUT_NS  100000000L

/*************************************
 *struct define
 ************************************/

static OS_TIME_LOOP_RANGE s_clockrange;


static void* Timer_Exe(void* data)
{
    struct timespec ts;
    static ULONG lasttime;

    printf("[%s:%d]\n",__FUNCTION__,__LINE__);    
    while(1) {
        printf("[%s:%d]\n",__FUNCTION__,__LINE__);    
        if(0 == clock_gettime (CLOCK_REALTIME, &ts)) {
            printf("[%s:%d][timer]:%d\n",__FUNCTION__,__LINE__,ts.tv_sec);    
        }
        EventLoop_Wakeup();
        printf("[%s:%d]\n",__FUNCTION__,__LINE__);    
    }
}

void Timer_Create(OS_TIME_LOOP_RANGE time)
{
    pthread_t id;
    printf("[%s:%d]\n",__FUNCTION__,__LINE__);    
    SINT ret = pthread_create(&id, NULL, Timer_Exe, 0);
    if(0 != ret) {
        printf("pthread_create is Error!!!!!!!!!!!!!!!!!!!!!\n");
    }

    printf("[%s:%d]\n",__FUNCTION__,__LINE__);    
    pthread_join(id,0);

}

void Timer_Run()
{
    
}

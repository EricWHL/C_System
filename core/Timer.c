#include <pthread.h>
#include <time.h>

#include "EventLoop.h"
#include "Timer.h"

/*************************************
 *enum define
 ************************************/

#define TIME_RANGE_1MS     1000000L   
#define TIME_RANGE_10MS    10000000L
#define TIME_RANGE_100MS   100000000L
#define TIME_RANGE_1S      1
#define TIME_RANGE_10S     10
/*************************************
 *struct define
 ************************************/
typedef struct _TIMER_RANGE_TBL {
    OS_TIME_LOOP_RANGE t_range;
    ULONG unit;
}TIMER_RANGE_TBL;


static OS_TIME_LOOP_RANGE s_clockrange;
static struct timespec lasttime;

static TIMER_RANGE_TBL s_time_r_tbl[OS_TIME_LOOP_RANGE_MAX] = {
    {OS_TIME_LOOP_RANGE_1MS,    TIME_RANGE_1MS},
    {OS_TIME_LOOP_RANGE_10MS,   TIME_RANGE_10MS},
    {OS_TIME_LOOP_RANGE_100MS,  TIME_RANGE_100MS},
    {OS_TIME_LOOP_RANGE_1S,     TIME_RANGE_1S},
    {OS_TIME_LOOP_RANGE_10S,    TIME_RANGE_10S}
};

static void* Timer_Exe(void* data)
{
    struct timespec ts;
    struct timespec cs;
    UINT i = 10;    
    printf("[%s:%d]\n",__FUNCTION__,__LINE__);
    printf("[%s:%d]last -> sec = %lld nsec = %lld\n",__FUNCTION__,__LINE__,lasttime.tv_sec, lasttime.tv_nsec);
    clock_gettime (CLOCK_REALTIME, &cs);
    memcpy(&lasttime, &cs, sizeof(struct timespec));
    
    do {
        printf("[%s:%d]range-> %d\n",__FUNCTION__,__LINE__,s_clockrange);
        printf("[%s:%d]last -> sec = %lld nsec = %lld\n",__FUNCTION__,__LINE__,lasttime.tv_sec, lasttime.tv_nsec);
       
        if(0 == clock_gettime (CLOCK_REALTIME, &ts)) {
            printf("[%s:%d]current -> sec = %lld nsec = %lld\n",__FUNCTION__,__LINE__,ts.tv_sec, ts.tv_nsec);
            switch (s_clockrange) {
            case OS_TIME_LOOP_RANGE_1MS:
            {
                if(((ts.tv_nsec/s_time_r_tbl[OS_TIME_LOOP_RANGE_1MS].unit)-(lasttime.tv_nsec/s_time_r_tbl[OS_TIME_LOOP_RANGE_1MS].unit)) >= 1) {
                    EventLoop_Wakeup();
                    memcpy(&lasttime, &ts, sizeof(struct timespec));
                }
            }
            break;
            case OS_TIME_LOOP_RANGE_10MS:
            {
                if(((ts.tv_nsec/s_time_r_tbl[OS_TIME_LOOP_RANGE_10MS].unit)-(lasttime.tv_nsec/s_time_r_tbl[OS_TIME_LOOP_RANGE_10MS].unit)) >= 10) {
                    EventLoop_Wakeup();
                    memcpy(&lasttime, &ts, sizeof(struct timespec));
                }
            }
            break;
            case OS_TIME_LOOP_RANGE_100MS:
            {
                if(((ts.tv_nsec/s_time_r_tbl[OS_TIME_LOOP_RANGE_100MS].unit)-(lasttime.tv_nsec/s_time_r_tbl[OS_TIME_LOOP_RANGE_100MS].unit)) >= 100) {
                    EventLoop_Wakeup();
                    memcpy(&lasttime, &ts, sizeof(struct timespec));
                }
            }
            break;
            case OS_TIME_LOOP_RANGE_1S:
            {
                if((ts.tv_sec-lasttime.tv_sec) >= 1) {
                    EventLoop_Wakeup();
                    memcpy(&lasttime, &ts, sizeof(struct timespec));
                }              
            }
            break;
            case OS_TIME_LOOP_RANGE_10S:
            {
                if((ts.tv_sec-lasttime.tv_sec) > 10) {
                    EventLoop_Wakeup();
                    memcpy(&lasttime, &ts, sizeof(struct timespec));
                }
            }
            break;
            default:
                break;
            }
        }
        
        printf("[%s:%d]\n",__FUNCTION__,__LINE__);    
    }while(0);
}

void Timer_Create(OS_TIME_LOOP_RANGE time)
{
    pthread_t id;
    SINT ret = 0;
    
    printf("[%s:%d]\n",__FUNCTION__,__LINE__);    

    s_clockrange = time;
    memset(&lasttime, 0x00, sizeof(struct timespec));
    
    ret = pthread_create(&id, NULL, Timer_Exe, 0);
    if(0 != ret) {
        printf("pthread_create is Error!!!!!!!!!!!!!!!!!!!!!\n");
    }

    printf("[%s:%d]\n",__FUNCTION__,__LINE__);
    
    pthread_join(id,0);

}

void Timer_Run()
{
    
}

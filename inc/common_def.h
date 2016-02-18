#ifndef _COMMON_DEF_H_
#define _COMMON_DEF_H_
/*************************************
 *enum define
 ************************************/
typedef enum {
	FUNC_TYPE_CALLBACK = 0,
	FUNC_TYPE_ACTION,
	FUNC_TYPE_EVENT_LOOP,
	FUNC_TYPE_MAILBOX,
	FUNC_TYPE_INVALID
}func_type;

/*************************************
 *struct define
 ************************************/

typedef struct _object {
	func_type type;
	void (*function)(void* param);
}st_object;

/*************************************
 *assert define
 ************************************/
#define ASSERT(exp) \
	do{ \
	if(!exp) { \
        printf("pointer is NULL file is:%s function is:%s line is:%d",__FILE__,__func__,__LINE__); \
    } \
}while(0)
#endif //_COMMON_DEF_H_

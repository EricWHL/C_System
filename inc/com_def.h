#ifndef _COM_DEF_H_
#define _COM_DEF_H_
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

#endif //_COMMON_DEF_H_

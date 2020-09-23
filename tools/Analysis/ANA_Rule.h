#ifndef _ANA_RULE_H
#define _ANA_RULE_H
#include "com.h"

const BYTE ANA_RULE_CRE_TASK[9]="CRE_TASK";

const BYTE ANA_RULE_TYPE_TASK[4]="TSK";
const BYTE ANA_RULE_TYPE_CYC[4]="CYC";

#define ANA_TASK_NAME(name) TASK_##name

#define ANA_TASK_NAME_SIZE  (64)

typedef enum _ANA_TASK_TYPE {
    ANA_TASK_TYPE_TASK,
    ANA_TASK_TYPE_CYC,
    ANA_TASK_TYPE_MAX
}ANA_TASK_TYPE;

typedef void (*ANA_CB_FUNC)(void* data);

typedef struct _ANA_Object {
    BYTE name[ANA_TASK_NAME_SIZE];
    ANA_TASK_TYPE type;
    UBYTE prioirty;
    ANA_CB_FUNC func;
    ULONG stackSize;
}ANA_Object;



#endif

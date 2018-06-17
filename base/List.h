#ifndef _LIST_H
#define _LIST_H

#include "com.h"

/*************************************
 *value define
 ************************************/
#define LIST_DATA_MAX_SIZE 256

/*************************************
 *enum type define
 ************************************/

typedef enum _LIST_OPE_RST {
    LIST_OPE_RST_OK = 0,
    LIST_OPE_RST_NG_LIST_NULL,
    LIST_OPE_RST_NG_DATA_NULL,
    LIST_OPE_RST_MAX
}LIST_OPE_RST;

/*************************************
 *struct type define
 ************************************/

typedef struct _Node{
    UBYTE data[LIST_DATA_MAX_SIZE];
    struct Node* pre;
    struct Node* next;
}Node;

typedef struct _List{
    Node* node;
}List;

/*************************************
 *functions type define
 ************************************/

List* List_Create();
void List_Destory(List* list);

BOOL List_isEmpty(List* list);

Node* List_pop(List* list);
LIST_OPE_RST List_push(List* list, void* data, UINT size);
LIST_OPE_RST List_append(List* list, void* data, UINT size);
LIST_OPE_RST List_insert(List* list, UINT index, void* data, UINT size);

UINT List_count(List* list);


#endif

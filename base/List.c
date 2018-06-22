#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "List.h"


List* List_Create()
{
    List* list = (List*)malloc(sizeof(List));

    if(NULL == list) {
        return NULL;
    }
    
    list->node = NULL;

    return list;
}

void List_Destory(List* list)
{
    
}

BOOL List_isEmpty(List* list)
{
    BOOL result = FALSE;

    if(NULL == list) {
        return TRUE;
    }

    if(NULL == list->node){
        result = TRUE;
    }
    else {
        result = FALSE;
    }
    
    return result;
}

Node* List_pop(List* list)
{
    Node* node= NULL;
    Node* swp = NULL;
    
    if(TRUE == List_isEmpty(list)) {
        return NULL;
    }

    node = list->node;
    swp = list->node->next;

    if(NULL != swp) {
        swp->pre = NULL;    
    }
    
    list->node = swp;
    
    return node;
}

LIST_OPE_RST List_push(List* list, void* data, UINT size)
{
    LIST_OPE_RST rst = LIST_OPE_RST_MAX;

    Node* node = NULL;
    Node* swp = NULL;
    Node* curnode = NULL;
    
    if(NULL == list) {
        rst = LIST_OPE_RST_NG_LIST_NULL;
        return rst;
    }

    if(NULL == data) {
        rst = LIST_OPE_RST_NG_DATA_NULL;
        return rst;
    }

    if(List_isEmpty(list)) {
        swp = (Node*)malloc(sizeof(Node));
        if(LIST_DATA_MAX_SIZE > size){
            memcpy(swp->data, data, size);    
        }
        else {
            memcpy(swp->data, data, LIST_DATA_MAX_SIZE);
        }
        swp->pre = NULL;
        swp->next = NULL;
        list->node = swp;

    }
    else {
        node = list->node;
    
        while(node) {
            curnode = node;
            node = node->next;
        }


        swp = (Node*)malloc(sizeof(Node));
        if(LIST_DATA_MAX_SIZE > size){
            memcpy(swp->data, data, size);    
        }
        else {
            memcpy(swp->data, data, LIST_DATA_MAX_SIZE);
        }
        swp->pre = curnode;
        swp->next = NULL;
        curnode->next = swp;
        
    }
    
    rst = LIST_OPE_RST_OK;
    return rst;    
}

LIST_OPE_RST List_append(List* list, void* data, UINT size)
{
    return List_push(list, data, size);
}

LIST_OPE_RST List_insert(List* list, UINT index, void* data, UINT size)
{
    LIST_OPE_RST rst = LIST_OPE_RST_MAX;
    UINT curidx = 0;
    Node* node = NULL;
    Node* swp = NULL;
    
    if(NULL == list) {
        rst = LIST_OPE_RST_NG_LIST_NULL;
        return rst;
    }

    if(NULL == data) {
        rst = LIST_OPE_RST_NG_DATA_NULL;
        return rst;
    }

    if(NULL == list->node) {
        rst = LIST_OPE_RST_NG_LIST_NULL;
        return rst;
    }

    node = list->node;

    while (node) {
        curidx ++;
        
        if(index == curidx) {
            swp = (Node*)malloc(sizeof(Node));
            if(LIST_DATA_MAX_SIZE > size){
                memcpy(swp->data, data, size);    
            }
            else {
                memcpy(swp->data, data, LIST_DATA_MAX_SIZE);
            }
            swp->next = node;
            swp->pre = node->pre;
            node->pre = swp;
            
            break;
        }

        node = node->next;
    }
    rst = LIST_OPE_RST_OK;
    return rst;
}

UINT List_count(List* list)
{
    UINT count = 0;
    Node* node = NULL;
    
    if(TRUE == List_isEmpty(list)) {
        return count;
    }

    node = list->node;
    while(node) {
        count ++;
        node = node->next;
    }
    
    return count;
}

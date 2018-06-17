#ifndef _LIST_H
#define _LIST_H

typedef struct _Node{
    void* data;
    struct Node* pre;
    struct Node* next;
}Node;

typedef struct _List{
    Node* node;
}List;

#endif

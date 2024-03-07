
#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "platform_types.h"

#define D_LINKED_LIST_DEBUG

typedef struct DNode
{
    uint32 DNodeData;
    struct DNode *prev;
    struct DNode *next;

}DNode_t;

/* comment */
typedef struct DoubleLinkedList
{
    DNode_t *head;
    DNode_t *tail;
}DoubleLinkedList_t;

typedef enum DLinkedList_Status
{
    LIST_OK,
    LIST_NOK,
    LIST_EMPTY,
    LIST_NULL_POINTER_PASSED
}DLinkedList_Status_t;


DoubleLinkedList_t *Create_Double_LinkedList(DLinkedList_Status_t *const ret_status);
DLinkedList_Status_t Destroy_Double_LinkedList(DoubleLinkedList_t *const dll_obj);

DLinkedList_Status_t Insert_Node_At_Beginning(DoubleLinkedList_t *const dll_obj, uint32 Data);
DLinkedList_Status_t Insert_Node_At_End(DoubleLinkedList_t *const dll_obj, uint32 Data);
DLinkedList_Status_t Insert_Node_After(DoubleLinkedList_t *const dll_obj,const uint32 Data, sint32 position); // zero-based
DLinkedList_Status_t Insert_Node_Before(DoubleLinkedList_t *const dll_obj,const uint32 Data, sint32 position); // zero-based

DLinkedList_Status_t Delete_Node_At_Beginning(DoubleLinkedList_t *const dll_obj);
DLinkedList_Status_t Delete_Node_At_End(DoubleLinkedList_t *const dll_obj);
DLinkedList_Status_t Delete_Node_At_Position(DoubleLinkedList_t *const dll_obj, sint32 position); // zero-based

DLinkedList_Status_t Display_All_Nodes_Forward(const DoubleLinkedList_t *const dll_obj);
DLinkedList_Status_t Display_All_Nodes_Reverse(const DoubleLinkedList_t *const dll_obj);

sint32 Get_Length(const DoubleLinkedList_t *const dll_obj);

#endif
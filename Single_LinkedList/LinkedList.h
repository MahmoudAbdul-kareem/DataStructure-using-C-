
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "platform_types.h"

#define LIST_DEBUG

typedef struct Node
{
    uint32 NodeData;
    struct Node *NodeLink;
}Node_t;

/* to create linked list Create (Node *) or (LinkedList_t) */
typedef Node_t* LinkedList_t;

typedef enum LinkedList_Status
{
    LIST_OK,
    LIST_NOK,
    LIST_EMPTY,
    LIST_NULL_POINTER_PASSED
}LinkedList_Status_t;

// done :)
LinkedList_Status_t Insert_Node_At_Beginning(Node_t **List, uint32 value);
LinkedList_Status_t Insert_Node_At_End(Node_t **List, uint32 value);
LinkedList_Status_t Insert_Node_After_Pos(Node_t *List, uint32 value, uint32 position); // the position is (one based)
LinkedList_Status_t Delete_Node_At_Beginning(Node_t **List);
LinkedList_Status_t Delete_Node_At_Pos(Node_t **List, uint32 position);

// copied!!

// done :)
LinkedList_Status_t Display_All_Nodes(const Node_t *List);
uint32 Get_Length(const Node_t *List);


#endif

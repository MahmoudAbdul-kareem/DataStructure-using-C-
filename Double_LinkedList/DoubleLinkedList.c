
#include "DoubleLinkedList.h"

static uint8 IsEmpty(const DoubleLinkedList_t *const dll_obj);

DoubleLinkedList_t *Create_Double_LinkedList(DLinkedList_Status_t *ret_status)
{
    DoubleLinkedList_t *dll_obj = NULL;

    if(NULL == ret_status)
    {
        #ifdef D_LINKED_LIST_DEBUG
        printf("LIST_NULL_POINTER_PASSED \n");
        #endif
        dll_obj = NULL;
    }
    else
    {
        dll_obj = (DoubleLinkedList_t *)malloc(sizeof(DoubleLinkedList_t));
        if(!dll_obj) // (NULL == dll_obj)
        {
            #ifdef D_LINKED_LIST_DEBUG
            printf("Can't allocate the object for Double Linked List in the heap! \n");
            #endif
            *ret_status = LIST_NOK;
            dll_obj = NULL;
        }
        else
        {
            // initialization
            dll_obj->head = dll_obj->tail = NULL;
            *ret_status = LIST_OK;
        }
    }

    return dll_obj;
}

DLinkedList_Status_t Destroy_Double_LinkedList(DoubleLinkedList_t *const dll_obj)
{
    DLinkedList_Status_t ret_status = LIST_NOK;

    if(NULL == dll_obj)
    {
        ret_status = LIST_NULL_POINTER_PASSED;
    }
    else
    {
        if(!IsEmpty(dll_obj)) // not empty
        {
            #ifdef D_LINKED_LIST_DEBUG
            printf("The list is NOT empty, Can't destroy! \n");
            #endif
            ret_status = LIST_NOK;
        }
        else
        {
            free(dll_obj);
            ret_status = LIST_OK;
        }   
    }

    return ret_status;
}

DLinkedList_Status_t Insert_Node_At_Beginning(DoubleLinkedList_t *const dll_obj, uint32 Data)
{
    DLinkedList_Status_t ret_status = LIST_NOK;
    DNode_t *new_node = NULL;

    if(NULL == dll_obj)
    {
        ret_status = LIST_NULL_POINTER_PASSED;
    }
    else
    {
        new_node = (DNode_t *)malloc(sizeof(DNode_t));
        if(!new_node)
        {
            // failed!
            #ifdef D_LINKED_LIST_DEBUG
            printf("Can't allocate the new Node in the heap! \n");
            #endif
            ret_status = LIST_NOK;
        }
        else
        {
            new_node->prev = NULL;
            new_node->DNodeData = Data;
            if(IsEmpty(dll_obj))
            {
                // insert first node
                dll_obj->head = dll_obj->tail = new_node;
                new_node->next = NULL;

            }
            else
            {
                new_node->next = dll_obj->head;
                dll_obj->head->prev = new_node;
                dll_obj->head = new_node;
            }
            ret_status = LIST_OK;
        }
    }

    return ret_status;
}

DLinkedList_Status_t Insert_Node_At_End(DoubleLinkedList_t *const dll_obj, uint32 Data)
{
    DLinkedList_Status_t ret_status = LIST_NOK;
    DNode_t *new_node = NULL;
    
    if(NULL == dll_obj)
    {
        ret_status = LIST_NULL_POINTER_PASSED;
    }
    else
    {
        new_node = (DNode_t *)malloc(sizeof(DNode_t));
        if(!new_node)
        {
            // failed!
            #ifdef D_LINKED_LIST_DEBUG
            printf("Can't allocate the new Node in the heap! \n");
            #endif
            ret_status = LIST_NOK;
        }
        else
        {
            new_node->next = NULL;
            new_node->DNodeData = Data;
            if(IsEmpty(dll_obj))
            {
                // insert first node
                dll_obj->head = dll_obj->tail = new_node;
                new_node->prev = NULL;
            }
            else
            {
                dll_obj->tail->next = new_node;
                new_node->prev = dll_obj->tail;
                dll_obj->tail = new_node;
            }
            ret_status = LIST_OK;
        }
    }

    return ret_status;
}

DLinkedList_Status_t Insert_Node_After(DoubleLinkedList_t *const dll_obj,const uint32 Data, sint32 position)
{
    DLinkedList_Status_t ret_status = LIST_NOK;
    sint32 list_length = Get_Length(dll_obj); // (5) : 0 -> 4
    DNode_t *new_node = NULL;
    DNode_t *temp_ptr = NULL;

    if(NULL == dll_obj)
    {
        ret_status = LIST_NULL_POINTER_PASSED;
    }
    else
    {
        if(IsEmpty(dll_obj))
        {
            #ifdef D_LINKED_LIST_DEBUG
            printf("The linked list is empty, Can't insert after! \n");
            #endif
            ret_status = LIST_EMPTY;
        }
        else if(position >= list_length || (position < 0))
        {
            #ifdef D_LINKED_LIST_DEBUG
            printf("Enter valid position from (0) to (%i) \n", (list_length - 1));
            #endif
            ret_status = LIST_NOK;
        }
        else if(position == (list_length - 1)) // last element
        {
            ret_status = Insert_Node_At_End(dll_obj, Data);
        }
        else
        {
            new_node = (DNode_t*)malloc(sizeof(DNode_t));
            if(!new_node)
            {
                // failed!
                #ifdef D_LINKED_LIST_DEBUG
                printf("Can't allocate the new Node in the heap! \n");
                #endif
                ret_status = LIST_NOK;
            }
            else
            {
                new_node->DNodeData = Data;
                temp_ptr = dll_obj->head;
                while (position--)
                {
                    temp_ptr = temp_ptr->next;
                }
                new_node->next = temp_ptr->next;
                temp_ptr->next->prev = new_node;
                temp_ptr->next = new_node;
                new_node->prev = temp_ptr;
                
                ret_status = LIST_OK;
            }
        }
    }

    return ret_status;
}

DLinkedList_Status_t Insert_Node_Before(DoubleLinkedList_t *const dll_obj,const uint32 Data, sint32 position)
{
    DLinkedList_Status_t ret_status = LIST_NOK;
    sint32 list_length = Get_Length(dll_obj);
    DNode_t *new_node = NULL;
    DNode_t *temp_ptr = NULL;

    if(NULL == dll_obj)
    {
        ret_status = LIST_NULL_POINTER_PASSED;
    }
    else
    {
        if(IsEmpty(dll_obj))
        {
            #ifdef D_LINKED_LIST_DEBUG
            printf("The linked list is empty, Can't insert after! \n");
            #endif
            ret_status = LIST_EMPTY;
        }
        else if((position >= list_length) || (position < 0))
        {
            #ifdef D_LINKED_LIST_DEBUG
            printf("Enter valid position from (0) to (%i) \n", (list_length - 1));
            #endif
            ret_status = LIST_NOK;
        }
        else if(0 == position) // first element
        {
            ret_status = Insert_Node_At_Beginning(dll_obj, Data);
        }
        else
        {
            new_node = (DNode_t*)malloc(sizeof(DNode_t));
            if(!new_node)
            {
                // failed!
                #ifdef D_LINKED_LIST_DEBUG
                printf("Can't allocate the new Node in the heap! \n");
                #endif
                ret_status = LIST_NOK;
            }
            else
            {
                new_node->DNodeData = Data;
                temp_ptr = dll_obj->head;
                while (position--)
                {
                    temp_ptr = temp_ptr->next;
                }
                new_node->prev = temp_ptr->prev;
                temp_ptr->prev->next = new_node;
                temp_ptr->prev = new_node;
                new_node->next = temp_ptr;
                
                ret_status = LIST_OK;
            }
        }
    }

    return ret_status;
}

DLinkedList_Status_t Delete_Node_At_Beginning(DoubleLinkedList_t *const dll_obj)
{
    DLinkedList_Status_t ret_status = LIST_NOK;

    if(NULL == dll_obj)
    {
        ret_status = LIST_NULL_POINTER_PASSED;
    }
    else
    {
        if(IsEmpty(dll_obj))
        {
            #ifdef D_LINKED_LIST_DEBUG
            printf("The linked list is empty, Can't delete any Node! \n");
            #endif
            ret_status = LIST_EMPTY;
        }
        else if(dll_obj->head == dll_obj->tail)
        {
            free(dll_obj->head);
            dll_obj->head = dll_obj->tail = NULL;
            ret_status = LIST_OK;
        }
        else
        {
            dll_obj->head = dll_obj->head->next;
            dll_obj->head->prev->next = NULL; // this line is NOT nessesary!
            free(dll_obj->head->prev);
            dll_obj->head->prev = NULL;
            ret_status = LIST_OK;
        }
    }

    return ret_status;
}

DLinkedList_Status_t Delete_Node_At_End(DoubleLinkedList_t *const dll_obj)
{
    DLinkedList_Status_t ret_status = LIST_NOK;

    if(NULL == dll_obj)
    {
        ret_status = LIST_NULL_POINTER_PASSED;
    }
    else
    {
        if(IsEmpty(dll_obj))
        {
            #ifdef D_LINKED_LIST_DEBUG
            printf("The linked list is empty, Can't delete any Node! \n");
            #endif
            ret_status = LIST_EMPTY;
        }
        else if(dll_obj->head == dll_obj->tail)
        {
            free(dll_obj->head);
            dll_obj->head = dll_obj->tail = NULL;
            ret_status = LIST_OK;
        }
        else
        {
            dll_obj->tail = dll_obj->tail->prev;
            dll_obj->tail->next->prev = NULL; // this line is NOT nessesary!
            free(dll_obj->tail->next);
            dll_obj->tail->next = NULL;
            ret_status = LIST_OK;
        }
    }

    return ret_status;
}

DLinkedList_Status_t Delete_Node_At_Position(DoubleLinkedList_t *const dll_obj, sint32 position)
{
    DLinkedList_Status_t ret_status = LIST_NOK;
    DNode_t *cur_node = NULL;
    sint32 list_length = Get_Length(dll_obj);

    if(NULL == dll_obj)
    {
        ret_status = LIST_NULL_POINTER_PASSED;
    }
    else
    {
        if(IsEmpty(dll_obj))
        {
            #ifdef D_LINKED_LIST_DEBUG
            printf("The linked list is empty, Can't delete any Node! \n");
            #endif
            ret_status = LIST_EMPTY;
        }
        else if((0 > position) || (position >= list_length))
        {
            #ifdef D_LINKED_LIST_DEBUG
            printf("Enter valid position from (0) to (%i) \n", (list_length - 1));
            #endif
            ret_status = LIST_NOK;
        }
        else if(0 == position)
        {
            ret_status = Delete_Node_At_Beginning(dll_obj);
        }
        else if((list_length - 1) == position)
        {
            ret_status = Delete_Node_At_End(dll_obj);
        }
        else
        {
            cur_node = dll_obj->head;
            while (position--)
            {
                cur_node = cur_node->next;
            }
            cur_node->prev->next = cur_node->next;
            cur_node->next->prev = cur_node->prev;
            free(cur_node);
            cur_node = NULL;
        }
    }

    return ret_status;
}

DLinkedList_Status_t Display_All_Nodes_Forward(const DoubleLinkedList_t *const dll_obj)
{
    DLinkedList_Status_t ret_status = LIST_NOK;
    DNode_t *temp_ptr = NULL;

    if(NULL == dll_obj)
    {
        ret_status = LIST_NULL_POINTER_PASSED;
    }
    else
    {
        if(IsEmpty(dll_obj))
        {
            #ifdef D_LINKED_LIST_DEBUG
            printf("The linked list is empty! \n");
            #endif
            ret_status = LIST_EMPTY;
        }
        else
        {
            temp_ptr = dll_obj->head;
            while (temp_ptr)
            {
                printf("(%i)-->", temp_ptr->DNodeData);
                temp_ptr = temp_ptr->next;
            }
            printf("NULL \n");
            ret_status = LIST_OK;
        }
    }

    return ret_status;
}

DLinkedList_Status_t Display_All_Nodes_Reverse(const DoubleLinkedList_t *const dll_obj)
{
    DLinkedList_Status_t ret_status = LIST_NOK;
    DNode_t *temp_ptr = NULL;

    if(NULL == dll_obj)
    {
        ret_status = LIST_NULL_POINTER_PASSED;
    }
    else
    {
        if(IsEmpty(dll_obj))
        {
            #ifdef D_LINKED_LIST_DEBUG
            printf("The linked list is empty! \n");
            #endif
            ret_status = LIST_EMPTY;
        }
        else
        {
            temp_ptr = dll_obj->tail;
            while (temp_ptr)
            {
                printf("(%i)-->", temp_ptr->DNodeData);
                temp_ptr = temp_ptr->prev;
            }
            printf("NULL \n");
            ret_status = LIST_OK;
        }
    }

    return ret_status;
}

static uint8 IsEmpty(const DoubleLinkedList_t *const dll_obj)
{
    return ((NULL == dll_obj->head) && (NULL == dll_obj->tail));
}

sint32 Get_Length(const DoubleLinkedList_t *const dll_obj)
{
    sint32 counter = 0;
    DNode_t *temp_ptr = NULL;

    if(NULL == dll_obj)
    {
        #ifdef D_LINKED_LIST_DEBUG
        printf("LIST_NULL_POINTER_PASSED \n");
        #endif
        counter = -1; // error!
    }
    else
    {
        temp_ptr = dll_obj->head;
        while (temp_ptr) // NULL != temp_ptr
        {
            temp_ptr = temp_ptr->next;
            counter++;
        }
    }

    return counter;
}

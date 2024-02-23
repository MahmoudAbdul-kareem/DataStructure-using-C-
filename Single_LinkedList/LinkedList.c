
#include "LinkedList.h"

static uint8 List_Is_Empty(Node_t *List);

LinkedList_Status_t Insert_Node_At_Beginning(Node_t **List, uint32 value)
{
    LinkedList_Status_t ret_status = LIST_NOK;

    if(NULL == List)
    {
        ret_status = LIST_NULL_POINTER_PASSED;
    }
    else
    {
        Node_t *new_node = NULL;
        new_node = (Node_t *)malloc(sizeof(Node_t));
        if(NULL == new_node)
        {
            #ifdef LIST_DEBUG
            printf("Can't allocate the heap memory for new node! \n");
            #endif
            ret_status = LIST_NOK;
        }
        else
        {
            new_node->NodeData = value;
            new_node->NodeLink = *List;
            *List = new_node;
            ret_status = LIST_OK;
        }
    }

    return ret_status;
}

LinkedList_Status_t Insert_Node_At_End(Node_t **List, uint32 value)
{
    LinkedList_Status_t ret_status = LIST_NOK;

    if(NULL == List)
    {
        ret_status = LIST_NULL_POINTER_PASSED;
    }
    else
    {
        Node_t *new_node = NULL;
        new_node = (Node_t *)malloc(sizeof(Node_t));
        if(!new_node) // (NULL == new_node)
        {
            #ifdef LIST_DEBUG
            printf("Can't allocate the heap memory for new node! \n");
            #endif
            ret_status = LIST_NOK;
        }
        else
        {
            new_node->NodeData = value;
            new_node->NodeLink = NULL; // last node
            if(List_Is_Empty(*List))
            {
                *List = new_node;
            }
            else
            {
                Node_t *cur = *List;
                /* move cur to the last node */
                while(cur->NodeLink)
                {
                    cur = cur->NodeLink;
                }
                cur->NodeLink = new_node;
            }
            ret_status = LIST_OK;
        }
    }

    return ret_status;
}

/* position is one based */
LinkedList_Status_t Insert_Node_After_Pos(Node_t *List, uint32 value, uint32 position)
{
    LinkedList_Status_t ret_status = LIST_NOK;
    uint32 list_length = Get_Length(List);
    uint32 iterator = 0;
    Node_t *new_node = NULL;

    if(NULL == List)
    {
        printf("Linked list is empty! \n");
        ret_status = LIST_EMPTY;
    }
    else
    {
        if(position > list_length)
        {
            printf("Enter valid position from (1) to (%i) \n", list_length);
            ret_status = LIST_NOK;
        }
        else
        {
            new_node = (Node_t *)malloc(sizeof(Node_t));
            if(!new_node)
            {
                #ifdef LIST_DEBUG
                printf("Can't allocate the heap memory for new node! \n");
                #endif
                ret_status = LIST_NOK;   
            }
            else
            {
                new_node->NodeData = value;
                for(iterator = 1; iterator < position; iterator++)
                {
                    List = List->NodeLink;
                }
                new_node->NodeLink = List->NodeLink;
                List->NodeLink = new_node;
                ret_status = LIST_OK;
            }
        }
    }

    return ret_status;
}

LinkedList_Status_t Delete_Node_At_Beginning(Node_t **List)
{
    LinkedList_Status_t ret_status = LIST_NOK;

    if(NULL == List)
    {
        ret_status = LIST_NULL_POINTER_PASSED;
    }
    else
    {
        if(List_Is_Empty(*List))
        {
            printf("Linked list is empty! Can't delete any node! \n");
            ret_status = LIST_EMPTY;
        }
        else
        {
            Node_t *first_node = *List;
            *List = first_node->NodeLink;
            first_node->NodeLink = NULL; /* first_node is a free node  (this line NOT nessesary!)*/
            free(first_node);
            ret_status = LIST_OK;
        }
    }

    return ret_status;
}

LinkedList_Status_t Delete_Node_At_Pos(Node_t **List, uint32 position)
{
    LinkedList_Status_t ret_status = LIST_NOK;
    uint32 list_length = Get_Length(*List);
    Node_t *cur = (*List)->NodeLink;
    Node_t *prev = *List;
    uint32 iterator = 0;

    if(NULL == List)
    {
        ret_status = LIST_NULL_POINTER_PASSED;
    }
    else
    {
        if(List_Is_Empty(*List))
        {
            printf("Linked list is empty! Can't delete any node! \n");
            ret_status = LIST_EMPTY;
        }
        else if((position > list_length) || (position <= 0))
        {
            printf("Enter valid position from (1) to (%i) \n", list_length);
            ret_status = LIST_NOK;
        }
        else
        {
            if(1 == position) // first node 
            {
                ret_status = Delete_Node_At_Beginning(List);
            }
            else
            {
                for(iterator = 2; iterator < position; iterator++)
                {
                    cur = cur->NodeLink;
                    prev = prev->NodeLink;
                }
                prev->NodeLink = cur->NodeLink;
                cur->NodeLink = NULL; /* NOT essential */
                free(cur);
                ret_status = LIST_OK;
            }
        }
    }

    return ret_status;
}

LinkedList_Status_t Display_All_Nodes(const Node_t *List)
{
    LinkedList_Status_t ret_status = LIST_NOK;

    if(NULL == List) /* linked list is empty */
    {
        #ifdef LIST_DEBUG
        printf("The linked list is empty! \n");
        #endif
        ret_status = LIST_EMPTY;
    }
    else
    {
        while(List)
        {
            printf("(%i)-->", List->NodeData);
            List = List->NodeLink;
        }
        printf("NULL \n");
        ret_status = LIST_OK;
    }

    return ret_status;
}

uint32 Get_Length(const Node_t *List)
{
    uint32 counter = 0;

    while(List)
    {
        counter++;
        List = List->NodeLink;
    }

    return counter;
}

static uint8 List_Is_Empty(Node_t *List)
{
    return (NULL == List);
}

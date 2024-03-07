
/*~~~~~~~~~~Includes~~~~~~~~~~~*/
#include "DynamicStack.h"

/*~~~~~~~~Declerations~~~~~~~~~*/
static uint8 StackIsFull(Stack_t *stack_obj);
static uint8 StackIsEmpty(Stack_t *stack_obj);

/*~~~~~~~Implementations~~~~~~~*/
Stack_t *StackCreate(uint32 max_size, StackStatus_t *ret_status)
{
    Stack_t *my_stack = NULL;

    if(NULL == ret_status)
    {
        #ifdef D_STACK_DEBUG
        printf("STACK_NULL_POINTER_PASSED \n");
        #endif
        my_stack = NULL;
    }
    else
    {
        /* Allocate the stack in the heap */
        my_stack = (Stack_t *)malloc(sizeof(Stack_t));
        if(!my_stack)
        {
            // fail to allocate structure!
            *ret_status = STACK_NOK;
            my_stack = NULL;
        }
        else
        {
            my_stack->ElementsCount = 0;
            my_stack->StackMaxSize = max_size;
            my_stack->StackTop = -1;
            my_stack->StackArray = (void **)calloc(max_size, sizeof(void *));
            if(!my_stack->StackArray)
            {
                // fail to allocate the array!
                *ret_status = STACK_NOK;
                free(my_stack);
                my_stack = NULL;
            }
            else
            {
                *ret_status = STACK_OK;
            }
        }
    }

    return my_stack;
}

Stack_t *StackDestroy(Stack_t *stack_obj, StackStatus_t *ret_status)
{
    if((NULL == stack_obj) || (NULL == ret_status))
    {
        #ifdef D_STACK_DEBUG
        printf("STACK_NULL_POINTER_PASSED \n");
        #endif
    }
    else
    {
        free(stack_obj->StackArray);
        free(stack_obj);
        *ret_status = STACK_OK;
    }

    return NULL;
}

StackStatus_t StackPush(Stack_t *stack_obj, void *item_ptr)
{
    StackStatus_t ret_status = STACK_NOK;

    if((NULL == stack_obj) || (NULL == item_ptr))
    {
        ret_status = STACK_NULL_POINTER_PASSED;
    }
    else
    {
        if(StackIsFull(stack_obj))
        {
            ret_status = STACK_FULL;
        }
        else
        {
            (stack_obj->StackTop)++;
            stack_obj->StackArray[stack_obj->StackTop] = item_ptr;
            (stack_obj->ElementsCount)++; // increment counter
            ret_status = STACK_OK;
        }
    }

    return ret_status;
}

void *StackPop(Stack_t *stack_obj, StackStatus_t *ret_status)
{
    void *item_ptr = NULL;

    if((NULL == stack_obj) || (NULL == ret_status))
    {
        #ifdef D_STACK_DEBUG
        printf("STACK_NULL_POINTER_PASSED \n");
        #endif
        item_ptr = NULL;
    }
    else
    {
        if(StackIsEmpty(stack_obj))
        {
            *ret_status = STACK_EMPTY;
            item_ptr = NULL;
        }
        else
        {
            /* copy the top to the item_ptr */
            item_ptr = stack_obj->StackArray[stack_obj->StackTop];
            (stack_obj->StackTop)--;
            (stack_obj->ElementsCount)--;
            *ret_status = STACK_OK;
        }
    }

    return item_ptr;
}

void *StackTop(Stack_t *stack_obj, StackStatus_t *ret_status)
{
    void *item_ptr = NULL;

    if((NULL == stack_obj) || (NULL == ret_status))
    {
        #ifdef D_STACK_DEBUG
        printf("STACK_NULL_POINTER_PASSED \n");
        #endif
        item_ptr = NULL;
    }
    else
    {
        if(StackIsEmpty(stack_obj))
        {
            *ret_status = STACK_EMPTY;
            item_ptr = NULL;
        }
        else
        {
            /* copy the top to the item_ptr */
            item_ptr = stack_obj->StackArray[stack_obj->StackTop];
            *ret_status = STACK_OK;
        }
    }

    return item_ptr;
}

StackStatus_t StackCount(Stack_t *stack_obj, uint32 *stack_count)
{
    StackStatus_t ret_status = STACK_NOK;

    if((NULL == stack_obj) || (NULL == stack_count))
    {
        ret_status = STACK_NULL_POINTER_PASSED;
    }
    else
    {
        *stack_count = stack_obj->ElementsCount;
        ret_status = STACK_OK;
    }

    return ret_status;
}


static uint8 StackIsFull(Stack_t *stack_obj)
{
    return (stack_obj->ElementsCount == stack_obj->StackMaxSize);
}

static uint8 StackIsEmpty(Stack_t *stack_obj)
{
    return (ZERO == stack_obj->ElementsCount);
}

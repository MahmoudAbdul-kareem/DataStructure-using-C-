
#include "stack.h"

/**
 * @brief Check if stack is full
 * @param my_stack pointer to the stack
 * @retval stack status (full, notfull)
*/
static stack_status_t stack_full(stack_t *my_stack)
{
    if(NULL == my_stack)
    {
        printf("error: null pointer passed! \n");
        return -1;
    }
    else
    {
        if((STACK_MAX_SIZE - 1) == my_stack->stack_pointer)
        {
            return STACK_FULL;
        }
        else
        {
            return STACK_NOT_FULL;
        }
    }
}

/**
 * @brief Check if stack is empty
 * @param my_stack pointer to the stack
 * @retval stack status (empty, notempty)
*/
static stack_status_t stack_empty(stack_t *my_stack)
{
    if(NULL == my_stack)
    {
        printf("error: null pointer passed! \n");
        return -1;
    }
    else
    {
        if(-1 == my_stack->stack_pointer)
        {
            return STACK_EMPTY;
        }
        else
        {
            return STACK_NOT_FULL;
        }
    }
}

/**
  * @brief Initialize the stack pointer
  * @param my_stack pointer to the stack
  * @retval status of initialization process
  */
ret_status_t stack_init(stack_t *my_stack)
{
    ret_status_t ret = R_NOK;

    if(NULL == my_stack)
    {
        ret = R_NOK;
    }
    else
    {
        my_stack->stack_pointer = -1;
        ret = R_OK;
    }

    return ret;
}

/**
 * @brief Push element to the stack
 * @param my_stack pointer to the stack
 * @param value variable to be pushed into the stack
 * @retval ret_status_t (R_NOK, R_OK)
*/
ret_status_t stack_push(stack_t *my_stack, uint32_t value)
{
    ret_status_t ret = R_NOK;

    if((NULL == my_stack) || (STACK_FULL == stack_full(my_stack)))
    {
        ret = R_NOK;
        #ifdef STACK_DEBUGGER
        printf("The stack is full, Can't push value (%i) \n", value);
        #endif
    }
    else
    {
        my_stack->stack_pointer++;
        my_stack->data[my_stack->stack_pointer] = value;
        #ifdef STACK_DEBUGGER
        printf("value (%i) pushed into the stack \n", value);
        #endif
        ret = R_OK;
    }

    return ret;
}

/**
 * @brief Pop the last element of the stack
 * @param my_stack pointer to the stack
 * @param value refrence variable to get the top
 * @retval ret_status_t (R_NOK, R_OK)
*/
ret_status_t stack_pop(stack_t *my_stack, uint32_t *value)
{
    ret_status_t ret = R_NOK;

    if((NULL == my_stack) || (NULL == value) || (STACK_EMPTY == stack_empty(my_stack)))
    {
        ret = R_NOK;
        #ifdef STACK_DEBUGGER
        printf("The stack is empty, Can't pop any value! \n");
        #endif
    }
    else 
    {
        *value = my_stack->data[my_stack->stack_pointer];
        my_stack->stack_pointer--;
        #ifdef STACK_DEBUGGER
        printf("value (%i) popped from the stack \n", *value);
        #endif
        ret = R_OK;
    }

    return ret;
}

/**
 * @brief Get the top of the stack
 * @param my_stack pointer to the stack
 * @param value refrence variable to get the top
 * @retval ret_status_t (R_NOK, R_OK)
*/
ret_status_t stack_top(stack_t *my_stack, uint32_t *value)
{
    ret_status_t ret = R_NOK;

    if((NULL == my_stack) || (NULL == value) || (STACK_EMPTY == stack_empty(my_stack)))
    {
        ret = R_NOK;
        #ifdef STACK_DEBUGGER
        printf("The stack is empty, Can't get any value! \n");
        #endif
    }
    else
    {
        *value = my_stack->data[my_stack->stack_pointer];
        #ifdef STACK_DEBUGGER
        printf("value (%i) is the top of the stack \n", *value);
        #endif
        ret = R_OK;
    }

    return ret;
}

/**
 * @brief Get the size of the stack
 * @param my_stack pointer to the stack
 * @param size refrence variable to get the size
 * @retval ret_status_t (R_NOK, R_OK)
*/
ret_status_t stack_size(stack_t *my_stack, uint32_t *size)
{
    ret_status_t ret = R_NOK;

    if((NULL == my_stack) || (NULL == my_stack))
    {
        ret = R_NOK;
        #ifdef STACK_DEBUGGER
        printf("NULL pointer passed to the function\n");
        #endif 
    }
    else
    {
        *size = (my_stack->stack_pointer + 1);
        #ifdef STACK_DEBUGGER
        printf("The stack size is (%i) \n", *size);
        #endif 
        ret = R_OK;
    }

    return ret;
}

/**
 * @brief display the elements in the stack
 * @param my_stack pointer to the stack
 * @retval ret_status_t (R_NOK, R_OK)
*/
ret_status_t stack_display(stack_t *my_stack)
{
    ret_status_t ret = R_NOK;
    sint32_t iterator = ZERO;

    if((NULL == my_stack) || (STACK_EMPTY == stack_empty(my_stack)))
    {
        ret = R_NOK;
        #ifdef STACK_DEBUGGER
        printf("The stack is empty, Can't get any value! \n");
        #endif
    }
    else
    {
        printf("the stack elements is [ ");
        for(iterator = my_stack->stack_pointer; iterator >= ZERO; iterator--)
        {
            printf("%i ", my_stack->data[iterator]);
        }
        printf("] \n");
        
        ret = R_OK;
    }

    return R_NOK;
}

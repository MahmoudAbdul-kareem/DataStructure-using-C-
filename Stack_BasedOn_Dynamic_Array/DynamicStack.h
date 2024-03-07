
#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "platform_types.h"

#define ZERO 0
#define D_STACK_DEBUG

typedef struct DynamicStack
{
    void **StackArray;
    uint32 StackMaxSize;
    sint32 StackTop;
    sint32 ElementsCount;
}Stack_t;

typedef enum StackStatus
{
    STACK_OK,
    STACK_NOK,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NULL_POINTER_PASSED
}StackStatus_t;

/**
 * @brief Allocate heap memory for the stack object
 * @param max_size maximum number of elements in the stack
 * @param ret_status status returned while performing this operation
 * @retval Pointer to the allocated stack object in the heap
*/
Stack_t *StackCreate(uint32 max_size, StackStatus_t *ret_status);

/**
 * @brief Free the memory allocated for the stack object
 * @param stack_obj pointer to the stack object
 * @param ret_status status returned while performing this operation
 * @retval NULL
*/
Stack_t *StackDestroy(Stack_t *stack_obj, StackStatus_t *ret_status);

/**
 * @brief Pushes an item into the stack
 * @param stack_obj pointer to the stack object
 * @param item_ptr pointer to be pushed
 * @retval Status returned while performing this operation
*/
StackStatus_t StackPush(Stack_t *stack_obj, void *item_ptr);

/**
 * @brief Popes the item on the top of the stack
 * @param stack_obj pointer to the stack object
 * @param ret_status status returned while performing this operation
 * @retval Pointer to user data if successful, NULL if underflow
*/
void *StackPop(Stack_t *stack_obj, StackStatus_t *ret_status);

/**
 * @brief Gives the item on the top of the stack
 * @param stack_obj pointer to the stack object
 * @param ret_status status returned while performing this operation
 * @retval Pointer to user data if successful, NULL if underflow
*/
void *StackTop(Stack_t *stack_obj, StackStatus_t *ret_status);

/**
 * @brief Returns number of elements in stack
 * @param stack_obj pointer to the stack object
 * @param stack_count number of elements in stack
 * @retval Status returned while performing this operation
*/
StackStatus_t StackCount(Stack_t *stack_obj, uint32 *stack_count);




#endif

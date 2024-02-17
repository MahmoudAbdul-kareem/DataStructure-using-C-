#ifndef _STACK_H_
#define _STACK_H_

#include "std_types.h"

#define STACK_MAX_SIZE 5
#define STACK_DEBUGGER

typedef struct stack
{
    uint32_t data[STACK_MAX_SIZE];
    sint32_t stack_pointer;
}stack_t;

typedef enum stack_status
{
    STACK_FULL,
    STACK_EMPTY,
    STACK_NOT_FULL
}stack_status_t;

/**
  * @brief Initialize the stack pointer
  * @param my_stack  pointer to stack
  * @retval status of initialization process
  */
ret_status_t stack_init(stack_t *my_stack);

/**
 * @brief Push element to the stack
 * @param my_stack pointer to the stack
 * @param value variable to be pushed into the stack
 * @retval ret_status_t (R_NOK, R_OK)
*/
ret_status_t stack_push(stack_t *my_stack, uint32_t value);

/**
 * @brief Pop the last element of the stack
 * @param my_stack pointer to the stack
 * @param value refrence variable to get the top
 * @retval ret_status_t (R_NOK, R_OK)
*/
ret_status_t stack_pop(stack_t *my_stack, uint32_t *value);

/**
 * @brief Get the top of the stack
 * @param my_stack pointer to the stack
 * @param value refrence variable to get the top
 * @retval ret_status_t (R_NOK, R_OK)
*/
ret_status_t stack_top(stack_t *my_stack, uint32_t *value);

/**
 * @brief Get the size of the stack
 * @param my_stack pointer to the stack
 * @param size refrence variable to get the size
 * @retval ret_status_t (R_NOK, R_OK)
*/
ret_status_t stack_size(stack_t *my_stack, uint32_t *size);

/**
 * @brief display the elements in the stack
 * @param my_stack pointer to the stack
 * @retval ret_status_t (R_NOK, R_OK)
*/
ret_status_t stack_display(stack_t *my_stack);



#endif
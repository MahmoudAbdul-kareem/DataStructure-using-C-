/**                       Documentation section
==========================================================================
  @file           : Application.c
  @author         : Mahmoud Abdul-kareem
  @brief          : Contains the functionality of my application
==========================================================================
*/

/* ~~~~~~~~~~~~~~~~~~~~~~ Includes Section Start ~~~~~~~~~~~~~~~~~~~~~~ */
#include <stdio.h>
#include "stack.h"
/* ~~~~~~~~~~~~~~~~~~~~~~~ Includes Section End ~~~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~~~~~~ Definition Section Start ~~~~~~~~~~~~~~~~~~~~ */
// macros:

// global variables:
stack_t my_stack1;
stack_t my_stack2;

uint32_t stack_pop_value = ZERO;
/* ~~~~~~~~~~~~~~~~~~~~~~ Definition Section End ~~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~ Global Decleration Section Start ~~~~~~~~~~~~~~~~~ */
// variables:

// prototypes:

/* ~~~~~~~~~~~~~~~~~~ Global Decleration Section End ~~~~~~~~~~~~~~~~~~ */


int main()
{
    ret_status_t ret = R_NOK;

    ret = stack_init(&my_stack1);
    if(R_NOK == ret)
    {
        printf("Can't initialize the my_stack1 !!\n");
    }
    else
    {
        ret = stack_push(&my_stack1, 10);
        ret = stack_push(&my_stack1, 20);
        ret = stack_push(&my_stack1, 30);
        ret = stack_push(&my_stack1, 40);
        ret = stack_push(&my_stack1, 50);
        ret = stack_push(&my_stack1, 60);
        ret = stack_push(&my_stack1, 70);

        ret = stack_pop(&my_stack1, &stack_pop_value);
        if(R_OK == ret)
        {
            printf("stack_pop_value = %i \n", stack_pop_value);
        }
        ret = stack_pop(&my_stack1, &stack_pop_value);
        if(R_OK == ret)
        {
            printf("stack_pop_value = %i \n", stack_pop_value);
        }
        ret = stack_pop(&my_stack1, &stack_pop_value);
        if(R_OK == ret)
        {
            printf("stack_pop_value = %i \n", stack_pop_value);
        }
        ret = stack_pop(&my_stack1, &stack_pop_value);
        if(R_OK == ret)
        {
            printf("stack_pop_value = %i \n", stack_pop_value);
        }
        ret = stack_pop(&my_stack1, &stack_pop_value);
        if(R_OK == ret)
        {
            printf("stack_pop_value = %i \n", stack_pop_value);
        }
        ret = stack_pop(&my_stack1, &stack_pop_value);
        if(R_OK == ret)
        {
            printf("stack_pop_value = %i \n", stack_pop_value);
        }
        printf("============================\n");
        
        uint32_t stack_top_value = ZERO;
        uint32_t stack_size_value = ZERO;
        ret = stack_push(&my_stack1, 99);
        ret = stack_top(&my_stack1, &stack_top_value);
        if(R_OK == ret)
        {
            printf("stack_top_value = %i \n", stack_top_value);
        }

        ret = stack_size(&my_stack1, &stack_size_value);
        ret = stack_push(&my_stack1, 18);
        ret = stack_push(&my_stack1, 12);
        ret = stack_push(&my_stack1, 46);
        
        ret = stack_display(&my_stack1);

    }


    ret = stack_init(&my_stack2);
    if(R_NOK == ret)
    {
        printf("Can't initialize the my_stack1 !!\n");
    }
    else{}

    
    return 0;
}


/* ~~~~~~~~~~~~~~~~~~~~ Sub-Program Section Start ~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~~~~~ Sub-Program Section End ~~~~~~~~~~~~~~~~~~~~~~ */

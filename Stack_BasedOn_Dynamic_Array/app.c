/**                       Documentation section
==========================================================================
  @file           : Application.c
  @author         : Mahmoud Abdul-kareem
  @brief          : Contains the functionality of my application
==========================================================================
*/

/* ~~~~~~~~~~~~~~~~~~~~~~ Includes Section Start ~~~~~~~~~~~~~~~~~~~~~~ */
#include <stdio.h>
#include "DynamicStack.h"
/* ~~~~~~~~~~~~~~~~~~~~~~~ Includes Section End ~~~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~~~~~~ Definition Section Start ~~~~~~~~~~~~~~~~~~~~ */
// macros:

// global variables:
Stack_t *Stack1 = NULL;

uint32 Stack1_Size = ZERO;
uint32 Stack1_Count = ZERO;
void *Stack1_Return = NULL;

uint32 Var1 = 0x11;
float32 Var2 = 2.14;
char Var3 = 'a';

/* ~~~~~~~~~~~~~~~~~~~~~~ Definition Section End ~~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~ Global Decleration Section Start ~~~~~~~~~~~~~~~~~ */
// variables:

// prototypes:

/* ~~~~~~~~~~~~~~~~~~ Global Decleration Section End ~~~~~~~~~~~~~~~~~~ */


int main()
{
    StackStatus_t Stack1_Status = STACK_NOK;
    printf("Enter number of stack 1 elements : ");
    scanf("%i", &Stack1_Size);

    Stack1 = StackCreate(Stack1_Size, &Stack1_Status);
    if(Stack1)
    {
        printf("Stack1 created successfully :) \n");
    }

    /*~~~~~~~~~~~Testing Start~~~~~~~~~~~*/

    Stack1_Status = StackPush(Stack1, &Var1); printf("Stack1_Status = %i \n", Stack1_Status);
    Stack1_Status = StackPush(Stack1, &Var2); printf("Stack1_Status = %i \n", Stack1_Status);
    Stack1_Status = StackPush(Stack1, &Var3); printf("Stack1_Status = %i \n", Stack1_Status);
    Stack1_Status = StackPush(Stack1, &Var3); printf("Stack1_Status = %i \n", Stack1_Status);

    Stack1_Status = StackCount(Stack1, &Stack1_Count); printf("Stack1_Status = %i \n", Stack1_Status);
    printf("Stack1_Count = %i \n", Stack1_Count);

    Stack1_Return = StackTop(Stack1, &Stack1_Status); printf("Stack1_Status = %i \n", Stack1_Status);
    printf("StackTop = %c \n", *((uint32 *)Stack1_Return));

    Stack1_Return = StackPop(Stack1, &Stack1_Status); printf("Stack1_Status = %i \n", Stack1_Status);
    printf("StackPop = %c \n", *((char *)Stack1_Return));
    Stack1_Return = StackPop(Stack1, &Stack1_Status); printf("Stack1_Status = %i \n", Stack1_Status);
    printf("StackPop = %f \n", *((float32 *)Stack1_Return));
    Stack1_Return = StackPop(Stack1, &Stack1_Status); printf("Stack1_Status = %i \n", Stack1_Status);
    printf("StackPop = 0x%X\n", *((uint32 *)Stack1_Return));

    Stack1_Status = StackCount(Stack1, &Stack1_Count); printf("Stack1_Status = %i \n", Stack1_Status);
    printf("Stack1_Count = %i \n", Stack1_Count);

    Stack1_Return = StackPop(Stack1, &Stack1_Status); printf("Stack1_Status = %i \n", Stack1_Status);
    
    /*~~~~~~~~~~~~Testing End~~~~~~~~~~~~*/



    Stack1 = StackDestroy(Stack1, &Stack1_Status);
    if(NULL == Stack1)
    {
        printf("Stack1 destroyed successfully :) \n");
    }

    return 0;
}


/* ~~~~~~~~~~~~~~~~~~~~ Sub-Program Section Start ~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~~~~~ Sub-Program Section End ~~~~~~~~~~~~~~~~~~~~~~ */

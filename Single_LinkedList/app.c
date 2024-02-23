/**                       Documentation section
==========================================================================
  @file           : Application.c
  @author         : Mahmoud Abdul-kareem
  @brief          : Contains the functionality of my application
==========================================================================
*/

/* ~~~~~~~~~~~~~~~~~~~~~~ Includes Section Start ~~~~~~~~~~~~~~~~~~~~~~ */
#include <stdio.h>
#include "LinkedList.h"

/* ~~~~~~~~~~~~~~~~~~~~~~~ Includes Section End ~~~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~~~~~~ Definition Section Start ~~~~~~~~~~~~~~~~~~~~ */
// macros:

// global variables:
LinkedList_t list1 = NULL;
Node_t *list2 = NULL;

/* ~~~~~~~~~~~~~~~~~~~~~~ Definition Section End ~~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~ Global Decleration Section Start ~~~~~~~~~~~~~~~~~ */
// variables:

// prototypes:

/* ~~~~~~~~~~~~~~~~~~ Global Decleration Section End ~~~~~~~~~~~~~~~~~~ */


int main()
{
    LinkedList_Status_t status = LIST_NOK;
    uint32 list1_length = 0;

    status = Display_All_Nodes(list1); printf("@ %i \n", status);
    list1_length = Get_Length(list1); printf("lenght = %i \n", list1_length); // 0
    status = Insert_Node_At_End(&list1, 4); printf("@ %i \n", status); // 4

    status = Insert_Node_At_Beginning(&list1, 5); printf("@ %i \n", status); // 5 4
    status = Insert_Node_At_Beginning(&list1, 6); printf("@ %i \n", status); // 6 5 4
    status = Insert_Node_At_Beginning(&list1, 7); printf("@ %i \n", status); // 7 6 5 4

    status = Insert_Node_At_End(&list1, 99); printf("@ %i \n", status); // 7 6 5 4 99 
    status = Insert_Node_At_End(&list1, 100); printf("@ %i \n", status); // 7 6 5 4 99 100

    status = Display_All_Nodes(list1); printf("@ %i \n", status);
    status = Display_All_Nodes(list1); printf("@ %i \n", status);
    list1_length = Get_Length(list1); printf("lenght = %i \n", list1_length);
    printf("-------------------\n");

    status = Insert_Node_After_Pos(list1, 88, 6); printf("@ %i \n", status);
    status = Display_All_Nodes(list1); printf("@ %i \n", status);

    status = Delete_Node_At_Beginning(&list1); printf("@ %i \n", status);
    status = Delete_Node_At_Beginning(&list1); printf("@ %i \n", status);
    status = Display_All_Nodes(list1); printf("@ %i \n", status);
    printf("-------------------\n");

    status = Delete_Node_At_Pos(&list1, 4); printf("@ %i \n", status);
    status = Display_All_Nodes(list1); printf("@ %i \n", status);

    return 0;
}


/* ~~~~~~~~~~~~~~~~~~~~ Sub-Program Section Start ~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~~~~~ Sub-Program Section End ~~~~~~~~~~~~~~~~~~~~~~ */


/**                       Documentation section
==========================================================================
  @file           : Application.c
  @author         : Mahmoud Abdul-kareem
  @brief          : Contains the functionality of my application
==========================================================================
*/

/* ~~~~~~~~~~~~~~~~~~~~~~ Includes Section Start ~~~~~~~~~~~~~~~~~~~~~~ */
#include <stdio.h>
#include "DoubleLinkedList.h"

/* ~~~~~~~~~~~~~~~~~~~~~~~ Includes Section End ~~~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~~~~~~ Definition Section Start ~~~~~~~~~~~~~~~~~~~~ */
// macros:

// global variables:
DoubleLinkedList_t *dll_1 = NULL;

/* ~~~~~~~~~~~~~~~~~~~~~~ Definition Section End ~~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~ Global Decleration Section Start ~~~~~~~~~~~~~~~~~ */
// variables:

// prototypes:

/* ~~~~~~~~~~~~~~~~~~ Global Decleration Section End ~~~~~~~~~~~~~~~~~~ */


int main()
{
    DLinkedList_Status_t status = LIST_NOK;
    sint32 length = 0;

    dll_1 = Create_Double_LinkedList(&status); printf("@ %i \n", status);
    length = Get_Length(dll_1); printf(">> %i \n", length);

    status = Delete_Node_At_Position(dll_1, 0); printf("@ %i \n", status);

    status = Insert_Node_At_Beginning(dll_1, 55); printf("@ %i \n", status);
    length = Get_Length(dll_1); printf(">> %i \n", length);

    status = Insert_Node_At_Beginning(dll_1, 33); printf("@ %i \n", status);
    status = Insert_Node_At_Beginning(dll_1, 44); printf("@ %i \n", status);

    status = Display_All_Nodes_Forward(dll_1); printf("@ %i \n", status);
    status = Insert_Node_After(dll_1, 666, 1); printf("@ %i \n", status);
    status = Display_All_Nodes_Forward(dll_1); printf("@ %i \n", status);
    printf("---------------------\n");

    status = Display_All_Nodes_Forward(dll_1); printf("@ %i \n", status);
    status = Insert_Node_Before(dll_1, 7777, 0); printf("@ %i \n", status);
    status = Display_All_Nodes_Forward(dll_1); printf("@ %i \n", status);
    status = Delete_Node_At_Position(dll_1, 3); printf("@ %i \n", status);
    status = Display_All_Nodes_Forward(dll_1); printf("@ %i \n", status);
    printf("---------------------\n");

    status = Insert_Node_At_End(dll_1, 55); printf("@ %i \n", status);
    length = Get_Length(dll_1); printf(">> %i \n", length);

    status = Destroy_Double_LinkedList(dll_1); printf("@ %i \n", status);

    return 0;
}


/* ~~~~~~~~~~~~~~~~~~~~ Sub-Program Section Start ~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~~~~~ Sub-Program Section End ~~~~~~~~~~~~~~~~~~~~~~ */

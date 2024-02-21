/**                       Documentation section
==========================================================================
  @file           : Application.c
  @author         : Mahmoud Abdul-kareem
  @brief          : Contains the functionality of my application
==========================================================================
*/

/* ~~~~~~~~~~~~~~~~~~~~~~ Includes Section Start ~~~~~~~~~~~~~~~~~~~~~~ */
#include <stdio.h>
#include "Queue.h"

/* ~~~~~~~~~~~~~~~~~~~~~~~ Includes Section End ~~~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~~~~~~ Definition Section Start ~~~~~~~~~~~~~~~~~~~~ */
// macros:

// global variables:
Queue_t *Queue1 = NULL;
uint32 value1 = 11;
float32 value2 = 2.2;
uint8 value3 = 'c';
char *name = "mahmoud";

uint32 int1 = 11;
uint32 int2 = 22;
uint32 int3 = 33;
uint32 int4 = 44;

void *ret_value = NULL;

sint32 Queue1ElementCounter = 0;

/* ~~~~~~~~~~~~~~~~~~~~~~ Definition Section End ~~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~ Global Decleration Section Start ~~~~~~~~~~~~~~~~~ */
// variables:

// prototypes:

/* ~~~~~~~~~~~~~~~~~~ Global Decleration Section End ~~~~~~~~~~~~~~~~~~ */


int main()
{
    QueueStatus_t queue_ret_status = QUEUE_NOK;
    Queue1 = QueueCreate(3, &queue_ret_status);

    // queue_ret_status = Enqueue(Queue1, &value1); // 11 2.2 c
    // queue_ret_status = Enqueue(Queue1, &value2);
    // queue_ret_status = Enqueue(Queue1, &value3);

    // ret_value = Dequeue(Queue1, &queue_ret_status);
    // printf("value is %i \n", *((uint32 *)ret_value)); // 11

    // ret_value = Dequeue(Queue1, &queue_ret_status);
    // printf("value is %.2f \n", *((float32 *)ret_value)); // 2.2

    // queue_ret_status = Enqueue(Queue1, &value1);
    // queue_ret_status = Enqueue(Queue1, &value2);

    // ret_value = Dequeue(Queue1, &queue_ret_status);
    // printf("value is %c \n", *((uint8 *)ret_value)); // c

    // ret_value = Dequeue(Queue1, &queue_ret_status);
    // printf("value is %i \n", *((uint32 *)ret_value)); // 11

    // ret_value = Dequeue(Queue1, &queue_ret_status);
    // printf("value is %.2f \n", *((float32 *)ret_value)); // 2.2

    // queue_ret_status = Enqueue(Queue1, (void *)(name));
    // ret_value = Dequeue(Queue1, &queue_ret_status);
    // printf("value is %s \n", (char *)ret_value); // mahmoud

    // queue_ret_status = Enqueue(Queue1, &value1); // 11 2.2 c
    // queue_ret_status = Enqueue(Queue1, &value2);
    // queue_ret_status = Enqueue(Queue1, &value3); // error


    queue_ret_status = Enqueue(Queue1, &int1);
    printf("front is: %i \n", *((uint32 *)QueueFront(Queue1, &queue_ret_status)));
    queue_ret_status = Enqueue(Queue1, &int2);
    queue_ret_status = Enqueue(Queue1, &int3);

    ret_value = Dequeue(Queue1, &queue_ret_status);
    printf("value is %i \n", *((uint32 *)ret_value)); // 11

    ret_value = Dequeue(Queue1, &queue_ret_status);
    printf("value is %i \n", *((uint32 *)ret_value)); // 22

    queue_ret_status = Enqueue(Queue1, &int1);
    queue_ret_status = Enqueue(Queue1, &int2);

    ret_value = Dequeue(Queue1, &queue_ret_status);
    printf("value is %i \n", *((uint32 *)ret_value)); // 33

    ret_value = Dequeue(Queue1, &queue_ret_status);
    printf("value is %i \n", *((uint32 *)ret_value)); // 11

    ret_value = Dequeue(Queue1, &queue_ret_status);
    printf("value is %i \n", *((uint32 *)ret_value)); // 22

    queue_ret_status = Enqueue(Queue1, &int4);
    ret_value = Dequeue(Queue1, &queue_ret_status);
    printf("value is %i \n", *((uint32 *)ret_value)); // 44

    queue_ret_status = QueueDisplay_uint32(Queue1); // empty
    Queue1ElementCounter = QueueCounter(Queue1, &queue_ret_status);
    printf("Queue1ElementCounter = %i \n", Queue1ElementCounter);
    ret_value = Dequeue(Queue1, &queue_ret_status); // error!

    queue_ret_status = Enqueue(Queue1, &int1);
    queue_ret_status = Enqueue(Queue1, &int2);
    queue_ret_status = Enqueue(Queue1, &int3);
    queue_ret_status = Enqueue(Queue1, &int4); // error!
    queue_ret_status = QueueDisplay_uint32(Queue1);

    Queue1ElementCounter = QueueCounter(NULL, &queue_ret_status);
    printf("Queue1ElementCounter = %i \n", Queue1ElementCounter);
    printf("queue_ret_status = %i \n", queue_ret_status); // 4 -> QUEUE_NULL_POINTER_PASSED

    queue_ret_status = QueueDestroy(Queue1);
    Queue1 = NULL;
    if(!queue_ret_status) // QUEUE_OK -> 0
    {
        printf("Queue Destryoyed successfully :) \n");
    }
    // Queue1->QueueMaxSize = 66;  /****** Warning ******/
    // printf(">>> %i \n", Queue1->QueueMaxSize);

    return 0;
}


/* ~~~~~~~~~~~~~~~~~~~~ Sub-Program Section Start ~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~~~~~ Sub-Program Section End ~~~~~~~~~~~~~~~~~~~~~~ */

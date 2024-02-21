
#include "Queue.h"

static uint8 QueueIsFull(Queue_t *queue_obj);
static uint8 QueueIsEmpty(Queue_t *queue_obj);

Queue_t *QueueCreate(uint32 max_size, QueueStatus_t *ret_status)
{
    Queue_t *my_queue = NULL;

    if(NULL == ret_status)
    {
        *ret_status = QUEUE_NULL_POINTER_PASSED;
        my_queue = NULL;
    }
    else
    {
        my_queue = (Queue_t *)malloc(sizeof(Queue_t));
        if(NULL == my_queue)
        {
            #ifdef QUEUE_DEBUG
            printf("Can't allocate the heap memory for Queue \n");
            #endif
            my_queue = NULL;
            *ret_status = QUEUE_NOK;
        }
        else
        {
            my_queue->QueueArray = (void **)calloc(max_size, sizeof(void *));
            if(!my_queue->QueueArray) // (NULL == my_queue->QueueArray)
            {
                #ifdef QUEUE_DEBUG
                printf("Can't allocate the heap memory for QueueArray \n");
                #endif

                free(my_queue);
                my_queue = NULL;
                *ret_status = QUEUE_NOK;
            }
            else
            {
                my_queue->QueueMaxSize = max_size;
                my_queue->QueueElementCount = 0;
                my_queue->QueueFront = -1;
                my_queue->QueueRear = -1;
                *ret_status = QUEUE_OK;
            }
        }
    }

    return my_queue;
}

QueueStatus_t QueueDestroy(Queue_t *queue_obj)
{
    QueueStatus_t ret_status = QUEUE_NOK;

    if(NULL == queue_obj)
    {
        ret_status = QUEUE_NULL_POINTER_PASSED;
    }
    else
    {
        free(queue_obj->QueueArray);
        free(queue_obj);
        ret_status = QUEUE_OK;
    }

    return ret_status;
}

QueueStatus_t Enqueue(Queue_t *queue_obj, void *item_ptr)
{
    QueueStatus_t ret_status = QUEUE_NOK;

    if((NULL == queue_obj) || (NULL == item_ptr))
    {
        ret_status = QUEUE_NULL_POINTER_PASSED;
    }
    else
    {
        if(QueueIsFull(queue_obj)) // can't Enqueue
        {
            ret_status = QUEUE_FULL;
            #ifdef QUEUE_DEBUG
            printf("Queue is full Can't Enqueue! \n");
            #endif
        }
        else
        {
            if(QueueIsEmpty(queue_obj)) // first element
            {
                queue_obj->QueueFront = 0;
                queue_obj->QueueRear = -1;
            }
            else {}

            (queue_obj->QueueRear)++;

            if(queue_obj->QueueRear == queue_obj->QueueMaxSize) // circular queue
            {
                queue_obj->QueueRear = 0;
            }
            else {}

            queue_obj->QueueArray[queue_obj->QueueRear] = item_ptr;
            (queue_obj->QueueElementCount)++;
        
            ret_status = QUEUE_OK;
        }
    }

    return ret_status;
}

void *Dequeue(Queue_t *queue_obj, QueueStatus_t *ret_status)
{
    void * item_ptr = NULL;

    if((NULL == queue_obj) || (NULL == ret_status))
    {
        *ret_status = QUEUE_NULL_POINTER_PASSED;
        item_ptr = NULL;
    }
    else
    {
        if(QueueIsEmpty(queue_obj))
        {
            #ifdef QUEUE_DEBUG
            printf("Queue is empty Can't Dequeue! \n");
            #endif
            *ret_status = QUEUE_EMPTY;
            item_ptr = NULL;
        }
        else
        {
            item_ptr = queue_obj->QueueArray[queue_obj->QueueFront];
            (queue_obj->QueueFront)++;

            if(queue_obj->QueueFront == queue_obj->QueueMaxSize) // circular queue
            {
                queue_obj->QueueFront = 0;
            }
            else {}

            (queue_obj->QueueElementCount)--;
            *ret_status = QUEUE_OK;
        }
    }

    return item_ptr;
}

void *QueueFront(Queue_t *queue_obj, QueueStatus_t *ret_status)
{
    void *item_ptr = NULL;

    if((NULL == queue_obj) || (NULL == ret_status))
    {
        *ret_status = QUEUE_NULL_POINTER_PASSED;
        item_ptr = NULL;
    }
    else
    {
        if(QueueIsEmpty(queue_obj))
        {
            #ifdef QUEUE_DEBUG
            printf("Queue is empty Can't get the front! \n");
            #endif
            *ret_status = QUEUE_EMPTY;
            item_ptr = NULL;
        }
        else
        {
            item_ptr = queue_obj->QueueArray[queue_obj->QueueFront];
            *ret_status = QUEUE_OK;
        }
    }

    return item_ptr;   
}

void *QueurRear(Queue_t *queue_obj, QueueStatus_t *ret_status)
{
    void *item_ptr = NULL;

    if((NULL == queue_obj) || (NULL == ret_status))
    {
        *ret_status = QUEUE_NULL_POINTER_PASSED;
        item_ptr = NULL;
    }
    else
    {
        if(QueueIsEmpty(queue_obj))
        {
            #ifdef QUEUE_DEBUG
            printf("Queue is empty Can't get the rear! \n");
            #endif
            *ret_status = QUEUE_EMPTY;
            item_ptr = NULL;
        }
        else
        {
            item_ptr = queue_obj->QueueArray[queue_obj->QueueRear];
            *ret_status = QUEUE_OK;
        }
    }

    return item_ptr;   
}

uint32 QueueCounter(Queue_t *queue_obj, QueueStatus_t *ret_status)
{
    sint32 counter = 0;

    if((NULL == queue_obj) || (NULL == ret_status))
    {
        *ret_status = QUEUE_NULL_POINTER_PASSED;
        counter = -1; // failed
    }
    else
    {
        counter = queue_obj->QueueElementCount;
        *ret_status = QUEUE_OK;
    }

    return counter;
}

static uint8 QueueIsFull(Queue_t *queue_obj)
{
    return (queue_obj->QueueElementCount == queue_obj->QueueMaxSize);
}

static uint8 QueueIsEmpty(Queue_t *queue_obj)
{
    return (0 == queue_obj->QueueElementCount);
}

QueueStatus_t QueueDisplay_uint32(Queue_t *queue_obj)
{
    QueueStatus_t ret_status = QUEUE_NOK;

    if(NULL == queue_obj)
    {
        ret_status = QUEUE_NULL_POINTER_PASSED;
    }
    else
    {
        sint32 iterator = 0;
        sint32 counter = 0;
        printf("Queue elements is [ ");
        for(iterator = queue_obj->QueueFront; counter < queue_obj->QueueElementCount; iterator = ((1 + iterator)%queue_obj->QueueMaxSize), counter++)
        {
            printf("%i ", *((uint32 *)queue_obj->QueueArray[iterator])); // display (uint32) elements only
        }
        printf("] \n");
        ret_status = QUEUE_OK;
    }

    return ret_status;
}

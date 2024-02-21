
#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "platform_types.h"

#define QUEUE_DEBUG

typedef struct Queue
{
    void **QueueArray;
    uint32 QueueMaxSize;
    sint32 QueueElementCount;
    sint32 QueueFront;
    sint32 QueueRear;
}Queue_t;

typedef enum QueueStatus
{
    QUEUE_OK = 0,
    QUEUE_NOK,
    QUEUE_FULL,
    QUEUE_EMPTY,
    QUEUE_NULL_POINTER_PASSED
}QueueStatus_t;

/**
 * @brief Allocate heap memory for the Queue object
 * @param max_size maximum number of elements in the Queue
 * @param ret_status status returned while performing this operation
 * @retval Pointer to the allocated Queue object in the heap
*/
Queue_t *QueueCreate(uint32 max_size, QueueStatus_t *ret_status);

/**
 * @brief Remove Queue From Heap
 * @param queue_obj Queue Allocated In Heap
 * @retval status returned while performing this operation
*/
QueueStatus_t QueueDestroy(Queue_t *queue_obj);

/**
 * @brief Insert New Number In Queue
 * @param queue_obj Queue Allocated In Heap
 * @param item_ptr New Element will Enqueue in Queue
 * @retval status of function if it's succeeded or not
*/
QueueStatus_t Enqueue(Queue_t *queue_obj, void *item_ptr);

/**
 * @brief Delete Number From Queue
 * @param queue_obj Queue Allocated In Heap
 * @param ret_status State of Function if Succeed or Not
 * @retval Deleted Data From Queue
*/
void *Dequeue(Queue_t *queue_obj, QueueStatus_t *ret_status);

/**
 * @brief Find Number Which Front Point on it
 * @param queue_obj Queue Allocated In Heap
 * @param ret_status State of Function if Succeed or Not
 * @retval Get the front data
*/
void *QueueFront(Queue_t *queue_obj, QueueStatus_t *ret_status);


/**
 * @brief Find Number Which Rear Point on it
 * @param queue_obj Queue Allocated In Heap
 * @param ret_status State of Function if Succeed or Not
 * @retval Get the rear data
*/
void *QueurRear(Queue_t *queue_obj, QueueStatus_t *ret_status);


/**
 * @brief Find Number Of Element In Queue
 * @param queue_obj Queue Allocated In Heap
 * @param ret_status State of Function if Succeed or Not
 * @retval Number of Element In Queue
*/
uint32 QueueCounter(Queue_t *queue_obj, QueueStatus_t *ret_status);

/**
 * @brief Display (uint32) Elements In the Queue
 * @param queue_obj Queue Allocated In Heap
 * @retval status of function if it's succeeded or not
*/
QueueStatus_t QueueDisplay_uint32(Queue_t *queue_obj);

#endif
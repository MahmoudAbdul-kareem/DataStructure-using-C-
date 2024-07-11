# Data Structures in C

This repository contains implementations of common data structures using the C programming language.

## Table of Contents
- [Introduction](#introduction)
- [Data Structures](#data-structures)
  - [Single Linked List](#single-linked-list)
  - [Double Linked List](#double-linked-list)
  - [Stack (Array)](#stack-array)
  - [Stack (Dynamic Array)](#stack-dynamic-array)
  - [Queue (Dynamic Circular Array)](#queue-dynamic-circular-array)
- [Usage](#usage)
- [Contributing](#contributing)

## Introduction

This project provides C implementations of some of the most common data structures. These implementations are useful for educational purposes, helping understand how data structures work under the hood.

## Data Structures

### Single Linked List
- **Description**: A linked list where each node points to the next node.
- **Features**:
  - Insert at beginning
  - Insert at end
  - Insert after position
  - Delete at beginning
  - Delete at position
  - Display all nodes

### Double Linked List
- **Description**: A linked list where each node has pointers to both the next and previous nodes.
- **Features**:
  - Create double linkedList
  - Destroy double linkedList
  - Insert at beginning
  - Insert at end
  - Insert after position
  - Insert before position
  - Delete at beginning
  - Delete at end 
  - Delete at position
  - Display all nodes (forward)
  - Display all nodes (reverse)

### Stack (Array)
- **Description**: A stack implemented using a static array.
- **Features**:
  - Stack init
  - Push
  - Pop
  - Peek
  - Size
  - Display
  - Check if stack is empty (helper funcion)
  - Check if stack is full (helper funcion)

### Stack (Dynamic Array)
- **Description**: A stack implemented using a dynamic array that resizes as needed.
- **Features**:
  - Create stack 
  - Destroy stack
  - Push
  - Pop
  - Peek
  - Size
  - Check if stack is empty (helper funcion)
  - Check if stack is full (helper funcion)

### Queue (Dynamic Circular Array)
- **Description**: A queue implemented using a dynamic circular array.
- **Features**:
  - Create queue
  - Destroy queue
  - Enqueue
  - Dequeue
  - Queue front 
  - Queue rear 
  - Display queue
  - Check if queue is empty (helper funcion)
  - Check if queue is full (helper funcion)

## Usage

To use any of these data structures, include the corresponding header file in your C program. For example, to use the single linked list:

```c
#include "LinkedList.h"

int main() {
    // Your code here
    return 0;
}
```

## Contributing

Contributions are welcome! Please fork this repository and submit pull requests.

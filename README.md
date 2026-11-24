# Data Structures — C++

Implementations and coursework from my **Data Structures** course, written in C++ with no external libraries. Each folder is a small, self-contained program.

## Contents

| Folder | What it implements |
| :--- | :--- |
| `linked list/` | Singly linked list: insert, delete, traverse |
| `Array/queue.cpp` | Queue backed by an array (circular buffer) |
| `queue/` | Queue implementation and a demo driver |
| `Stack/` | Stack implementation and a demo driver |
| `BST/` | Binary Search Tree: insert, search, and traversals |
| `Task2/Deletion BST.cpp` | Node deletion from a BST, including the two-children case |
| `Task3/graph.cpp` | Graph representation and traversal |
| `simple university system/` | Small system for students registering for subjects, built on a linked list |

## Concepts covered

- Linear structures: arrays, linked lists, stacks, queues
- Trees: binary search trees, insertion, search, deletion
- Graphs: representation and traversal
- Pointer management and manual memory handling in C++

## Build and run

Every folder has a standalone `.cpp` file:

```bash
g++ -std=c++17 "linked list/test.cpp" -o list
./list
```

On Windows, `g++` from MinGW works the same way.

## Note

The compiled `.exe` files in this repo are leftover build artefacts from the course — build from source instead of running them.

## Also included

`Task2/code.pdf` and `Task3/summary graph.pdf` are the written explanations submitted alongside the code.

# Algorithms_DataStructures_Cpp
A repository to explore algorithms and data structures, ranging from recursion to graphs and more in C++


# Data Structures and Algorithms Overview

## Recursion
- Definition: A programming technique where a function calls itself to solve a problem by breaking it down into smaller subproblems.
- Examples: Factorial calculation, Fibonacci sequence, Tower of Hanoi.
- Key Concepts: Base case, recursive case, stack memory usage.

## Arrays and Lists
- Definition: A collection of elements stored in contiguous memory locations.
- Arrays:
  - Fixed-size arrays: Elements are stored in a fixed-size memory block.
  - Dynamic arrays: Arrays that can grow or shrink dynamically.
- Lists:
  - Linked lists: Elements are stored in nodes with pointers/references to the next element.
  - Doubly linked lists: Linked lists with pointers/references to both next and previous elements.
  - Circular linked lists: Linked lists where the last element points to the first element.
- Operations: Insertion, deletion, search, access.
- Time Complexity: Varies depending on the operation and data structure implementation.

## Stacks and Queues
- Definition:
  - Stacks: Last-In-First-Out (LIFO) data structure.
  - Queues: First-In-First-Out (FIFO) data structure.
- Implementation: Arrays or linked lists.
- Operations: Push (add), pop (remove), top/peek (access topmost element), enqueue (add), dequeue (remove).
- Applications: Function call stack, undo/redo operations, breadth-first search (BFS).

## Trees
- Definition: A hierarchical data structure with nodes connected by edges.
- Types:
  - Binary trees: Each node has at most two children.
  - Binary search trees (BST): Left child < parent < right child.
  - Balanced trees: Red-Black trees, AVL trees, etc., to maintain balance.
- Operations: Insertion, deletion, search, traversal (in-order, pre-order, post-order).
- Applications: File systems, expression parsing, decision trees.

## Graphs
- Definition: A collection of nodes (vertices) connected by edges.
- Types:
  - Directed graph: Edges have a direction.
  - Undirected graph: Edges have no direction.
  - Weighted graph: Edges have weights/costs.
- Representations: Adjacency matrix, adjacency list.
- Traversal: Depth-First Search (DFS), Breadth-First Search (BFS).
- Algorithms: Dijkstra's algorithm, Bellman-Ford algorithm, Prim's algorithm, Kruskal's algorithm.

## Hash Tables
- Definition: A data structure that maps keys to values using a hash function.
- Operations: Insertion, deletion, search.
- Collision handling: Chaining (linked lists), open addressing (linear probing, quadratic probing).
- Time complexity: Average case O(1) for insertion, deletion, and search (if hash function is well-distributed).
- Applications: Caches, symbol tables, dictionaries.

## Sorting Algorithms
- Definition: Algorithms that arrange elements in a particular order.
- Types:
  - Comparison-based sorting: Bubble sort, selection sort, insertion sort, [merge sort](./practice_01/mergesort.cpp), quicksort, heapsort.
  - Non-comparison-based sorting: Counting sort, radix sort, bucket sort.
- Time complexity: Varies depending on the algorithm (e.g., O(n^2) for bubble sort, O(n log n) for merge sort).
- Stable sorting: Maintains the relative order of equal elements.
- In-place sorting: Sorts the elements using only a constant amount of additional memory.

This is just a high-level overview of some common data structures and algorithms. Each topic can be explored in detail to understand their implementation, complexities, and various applications.

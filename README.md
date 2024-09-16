# Data Structures in C++

This repository contains various data structures implemented in C++. These implementations cover a range of algorithms and structures such as graphs, trees, lists, hash tables, and more. Below is a directory structure and a brief description of each component.

## Table of Contents
- [Graphs](#graphs)
  - [Dijkstra](#dijkstra)
  - [Graph](#graph)
  - [Kruskal](#kruskal)
  - [Minimum Cut](#minimum-cut)
- [Hash Table](#hash-table)
- [Lists](#lists)
  - [Double-Linked List](#double-linked-list)
  - [List (Form 1)](#list-form-1)
  - [List (Form 2)](#list-form-2)
- [Trees](#trees)
  - [AVL Tree](#avl-tree)
  - [Binary Search Tree](#binary-search-tree)
  - [Binary Tree](#binary-tree)
  - [Binary Tree Array](#binary-tree-array)
  - [Heap (Minimum)](#heap-minimum)
  - [Red-Black Tree](#red-black-tree)
  
---

## Graphs

### Dijkstra
Implementation of Dijkstra's algorithm for finding the shortest paths in a graph.

Files:
- `Edge.h`: Defines the structure for graph edges.
- `Graph.h`: Implements the graph structure.
- `Node.h`: Defines the nodes in the graph.
- `main.cpp`: Executes Dijkstra's algorithm.

### Graph
A basic graph implementation that supports basic operations like adding nodes and edges.

Files:
- `Graph.h`: Defines the graph structure.
- `Node.h`: Defines the graph nodes.
- `main.cpp`: Example usage of the graph structure.

### Kruskal
An implementation of Kruskal's algorithm for finding the Minimum Spanning Tree (MST) of a graph.

Files:
- `BinarySearchTree.h`: Implements a Binary Search Tree used in Kruskal's algorithm.
- `BinarySearchTreeNode.h`: Nodes of the Binary Search Tree.
- `Graph.h`: Defines the graph structure used in Kruskal's algorithm.
- `List.h`: Implements a generic list.
- `ListNode.h`: Defines the nodes for the list.
- `main.cpp`: Main file to execute the algorithm.
- `TimeTravelBolivia.txt`: Sample file used in testing.

### Minimum Cut
This section implements a minimum cut algorithm.

Files:
- `BinarySearchTree.h`: Implements a Binary Search Tree.
- `BinarySearchTreeNode.h`: Defines the nodes for the Binary Search Tree.
- `Graph.h`: Graph structure for the minimum cut algorithm.
- `List.h`: Generic list structure used in the algorithm.
- `ListNode.h`: Defines the nodes for the list.
- `main.cpp`: Runs the minimum cut algorithm.
- `file.txt`, `fileTest.txt`: Test files for input data.

---

## Hash Table
An implementation of a hash table using separate chaining for collision resolution.

Files:
- `Hash.h`: Implements the hash table.
- `List.h`: Used for handling collisions with linked lists.
- `Node.h`: Defines the nodes in the hash table.
- `main.cpp`: Example usage of the hash table.

---

## Lists

### Double-Linked List
A doubly linked list implementation.

Files:
- `List.h`: Implements the double-linked list.
- `Node.h`: Defines the nodes of the list.
- `main.cpp`: Example usage of the double-linked list.

### List (Form 1)
A simple linked list implementation (Form 1).

Files:
- `List.h`: Implements the linked list.
- `main.cpp`: Example usage of the list.

### List (Form 2)
Another variation of a simple linked list (Form 2).

Files:
- `List.h`: Implements the linked list.
- `main.cpp`: Example usage of the list.

---

## Trees

### AVL Tree
An implementation of an AVL tree, a self-balancing binary search tree.

Files:
- `Tree.h`: Defines the AVL tree structure.
- `Node.h`: Nodes used in the AVL tree.
- `main.cpp`: Runs the AVL tree implementation.
- `ThousandNumbers.txt`: Sample data for testing.

### Binary Search Tree
A classic Binary Search Tree (BST) implementation.

Files:
- `BinarySearchTree.h`: Implements the binary search tree.
- `Node.h`: Nodes for the BST.
- `main.cpp`: Runs the BST implementation.
- `ThousandNumbers.txt`: Sample data for testing.

### Binary Tree
A binary tree implementation with various tree traversal methods.

Files:
- `BinaryTree.h`: Defines the binary tree structure.
- `Node.h`: Nodes for the binary tree.
- `main.cpp`: Runs the binary tree implementation.

### Binary Tree Array
A binary tree implementation using an array.

Files:
- `BinaryTree.h`: Defines the binary tree stored in an array.
- `main.cpp`: Runs the binary tree array implementation.

### Heap (Minimum)
A minimum heap implementation with heap sort functionality.

Files:
- `Heap.h`: Defines the heap structure.
- `main.cpp`: Example usage of the heap.

### Red-Black Tree
An implementation of a Red-Black tree, a balanced binary search tree.

Files:
- `RedBlackTree.h`: Defines the Red-Black tree structure.
- `Node.h`: Defines the nodes of the Red-Black tree.
- `main.cpp`: Runs the Red-Black tree implementation.
- `ThousandNumbers.txt`: Sample data for testing.

---

## License
This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.

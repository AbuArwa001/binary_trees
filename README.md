# 0x1D. C - Binary trees

This project is part of the SE Foundations curriculum at ALX. It is a group project that aims to teach the basics of binary trees, their types, and their traversal methods.

## Learning Objectives

At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

- What is a binary tree
- What is the difference between a binary tree and a Binary Search Tree
- What is the possible gain in terms of time complexity compared to linked lists
- What are the depth, the height, the size of a binary tree
- What are the different traversal methods to go through a binary tree
- What is a complete, a full, a perfect, a balanced binary tree

## Requirements

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project, is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You are not allowed to use global variables
- No more than 5 functions per file
- You are allowed to use the standard library
- The prototypes of all your functions should be included in your header file called binary_trees.h
- Don’t forget to push your header file
- All your header files should be include guarded
- There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.

## Data structures

Please use the following data structures and types for binary trees. Don’t forget to include them in your header file.

Basic Binary Tree
```
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};
```

typedef struct binary_tree_s binary_tree_t;
Binary Search Tree
typedef struct binary_tree_s bst_t;
AVL Tree
typedef struct binary_tree_s avl_t;
Max Binary Heap
typedef struct binary_tree_s heap_t;

## Tasks

0. New node
Write a function that creates a binary tree node

- Prototype: binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
- Where parent is a pointer to the parent node of the node to create
- And value is the value to put in the new node
- When created, a node does not have any child
- Your function must return a pointer to the new node, or NULL on failure

## Installation

To use this project, you need to clone the repository and compile the files with gcc.

```bash
git clone [5](https://github.com/yourusername/yourproject.git)
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o binary_trees
```
### Usage
To run the project, execute the binary_trees file with the task number as an argument.

./binary_trees 0

### Contributing
This project is for learning purposes only, but if you want to contribute, you can follow these steps:

* Fork the repository.
* Create a new branch: git checkout -b feature-name.
* Make your changes.
* Push your branch: git push origin feature-name.
* Create a pull request.
### License
This project is licensed under the MIT License.


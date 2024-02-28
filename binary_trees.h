#ifndef BINARY_TREES
#define BINARY_TREES

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

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;
void binary_tree_print(const binary_tree_t *);

/**
 * binary_tree_node - a function that creates a binary tree node
 * @parent: parent node
 * @value: value of the current node
 *
 * Return:  a pointer to the new node, or NULL on failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
/**
 * binary_tree_insert_left - a function that inserts a
 *   node as the left-child of another node
 * @parent: a pointer to the node to insert the lef-child in
 * @value: the value to store in the new node
 * Return: return a pointer to the created node  or NULL
 *          on failure
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
/**
 * binary_tree_insert_right - inserts node as
 *                      the right-child of another node
 * @parent: pointer to the node to insert the right child in
 * @value: value to store in the new node
 * Return: returns a pointer to the created node or
 *          NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
/**
 * binary_tree_delete - Deletes  an entir binary tree
 * @tree: a pointer to the root node of the tree
 * Return: return NULL
*/
void binary_tree_delete(binary_tree_t *tree);
/**
 * binary_tree_is_leaf -  checks if a node is a leaf
 * @node: Pointer to the node to check
 * Return: return 1 if node is leaf otherwise 0
*/
int binary_tree_is_leaf(const binary_tree_t *node);
/**
 * binary_tree_is_root -  checks if a node is a root
 * @node: Pointer to the node to check
 * Return: return 1 if node is leaf otherwise 0
*/
int binary_tree_is_root(const binary_tree_t *node);
#include <stdlib.h>
/**
 * binary_tree_preorder - goes through binary tree using pre-order
 * @tree: pointer to the root node of the tree to travers
 * @func: is a pointer to a function to call for each node
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each mode
*/

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
/**
 * binary_tree_postorder - Goes through a binary tree
 *                          using post-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each mode
*/

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
/**
 * binary_tree_height - Measures height of a binary tree.
 * @tree: pointer to the root node
 * Return: returns he max height
*/
size_t binary_tree_height(const binary_tree_t *tree);
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the deth
 * Return: depth of the node
*/
size_t binary_tree_depth(const binary_tree_t *tree);
/**
 * binary_tree_size - Measurs the size of a binary tree
 * @tree: A pointer to root node to be measured
 * Return: size of the tree;
*/
size_t binary_tree_size(const binary_tree_t *tree);
/**
 * binary_tree_leaves -  a function  that counts the leavs in a binary tree
 * @tree: a pointer to the root node of the tree to count
 * Return: retunrs 0 if NULL else number of leaves
*/
size_t binary_tree_leaves(const binary_tree_t *tree);
/**
 * binary_tree_nodes - Function that counts the nodes withat leaas 1 child
 * @tree: A pointer to the root node of the tree
 * Return: returns number of nodes with children
*/
size_t binary_tree_nodes(const binary_tree_t *tree);
/**
 * binary_tree_balance - Measurs the balance factor of binary tree
 * @tree: pointer to the root node of the tree
 * Return: Te balance factor
*/
int binary_tree_balance(const binary_tree_t *tree);
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: Return 1 if true otherwise return 0
*/
int binary_tree_is_full(const binary_tree_t *tree);
/***
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree:  pointer to the root node of the tree to check
 * Return: returns 1 if true 0 if false
*/
int binary_tree_is_perfect(const binary_tree_t *tree);
#endif

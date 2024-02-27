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
#endif

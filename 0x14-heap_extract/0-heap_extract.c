#include "binary_trees.h"

/**
 * last_node - Finds the last node of a heap
 * @root: Pointer to the root of the heap
 * Return: Pointer to the last node.
 * NULL if the heap is empty.
 */
heap_t *last_node(heap_t *root)
{
	int lftHeight, rtHeight = 0;

	if (!(root->left) && !(root->right))
		return (root);
	if (root->left)
		lftHeight = binary_tree_height(root->left);
	if (root->right)
		rtHeight = binary_tree_height(root->right);
	if (lftHeight == rtHeight)
		return (last_node(root->left));
	else
		return (last_node(root->right));
}

/**
 * binary_tree_height - heap_t *root
 * @root: pointer to the node to measure the height
 * description: function that measures the height of a binary root
 * Return: 0 if root is NULL
 */
int binary_tree_height(heap_t *root)
{
	int lftHeight;
	int rtHeight;


	/* If root is NULL, your function must return 0 */
	if (!root)
		return (0);

	/* if no child to right or left, return 0 */
	if (!root->left && !root->right)
		return (0);

	/* Since the height of the root is defined as the largest path */
	/* from the root to a leaf, we can recursively compute the height */
	/* of the left and right sub-trees. */

	/* We can apply the definition of the height on the sub-trees now.*/
	lftHeight = binary_tree_height(root->left);
	rtHeight = binary_tree_height(root->right);

	/* Find the height of both subtrees and use the larger one */
	/* add 1 to it for the current node */
	if (lftHeight > rtHeight)
		return (lftHeight + 1);
	return (rtHeight + 1);
}

/**
 * heap_extract - heap_t **root
 * @root: double pointer to the root node of the heap
 * Description: Function that extracts the root node of a Max Binary Heap.
 * Root node must be freed and replace by the last level-order node of the
 * heap. Once replaced, re-heapify the heap.
 * Return: Value stored in the root node. Else 0 if function fails.
 */
int heap_extract(heap_t **root)
{
	int theRoot = 0;
	heap_t *lastNode;

	/* If root is NULL or root's n is NULL, return 0 */
	if (!root || !(*root) || !(*root)->n)
		return (0);

	/* Store the value of the root node */
	theRoot = (*root)->n;

	/* If root has no children, free root and set root to NULL */
	if (!(*root)->left)
	{
		free(*root);
		*root = NULL;
		return (theRoot);
	}
	lastNode = last_node(*root);
	(*root)->n = lastNode->n;

	if (lastNode->parent->left == lastNode)
		lastNode->parent->left = NULL;
	lastNode->parent->right = NULL;

	free(lastNode);
	heapify(*root);
	return (theRoot);
}

/**
 * heapify - heap_t **root
 * @root: double pointer to the root node of the heap
 * Description: Function that re-heaps the heap.
 * Return: void
 */
void heapify(heap_t *root)
{
	int buff;
	heap_t *tempRoot;

	/* If no children, leave function */
	if (!root->left && !root->right)
		return;

	tempRoot = root->left;

	/* If right child exists and right child's n is greater */
	/* than make right child the new tempRoot */
	if (root->right && root->right->n > tempRoot->n)
		tempRoot = root->right;

	/* If tempRoot's n is greater than root's n, swap and heapify */
	if (tempRoot->n > root->n)
	{
		buff = root->n;
		root->n = tempRoot->n;
		tempRoot->n = buff;
		heapify(tempRoot);
	}
}

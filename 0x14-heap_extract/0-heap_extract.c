#include "binary_trees.h"

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
	int theRoot;

	/* If root is NULL or root's n is NULL, return 0 */
	if (!root || !(*root)->n)
		return (0);

	/* Store the value of the root node */
	theRoot = (*root)->n;

	/* If root has a left child, replace root with the left child */
	if ((*root)->left)
		*root = (*root)->left;

	/* If root has a right child, replace root with the right child */
	else if ((*root)->right)
		*root = (*root)->right;

	/* If root has no children, replace root with NULL */
	else
		*root = NULL;

	/* Re-heapify */
	if (*root)
		heap_sift_down(*root);

	return (theRoot);
}

/**
 * heap_sift_down - heap_t **root
 * @root: double pointer to the root node of the heap
 * Description: Function that sifts down a Max Binary Heap node.
 * Return: void
 */
void heap_sift_down(binary_tree_t *root)
{
	heap_t *theLeft;
	heap_t *theRight;
	heap_t *theRoot;

	theRoot = root;
	theLeft = root->left;
	theRight = root->right;

	/* If root has a left child, and root's value is less than or */
	/* equal to the left child's value, swap root w the left child */
	if (theLeft && theRoot->n <= theLeft->n)
		swap(&theRoot, &theLeft);
	/* If root has a right child, and root's value is less than or */
	/* equal to the right child's value, swap root w the right child */
	if (theRight && theRoot->n <= theRight->n)
		swap(&theRoot, &theRight);
	/* If root is not the root of the tree, sift down the new root */
	if (theRoot != root)
		heap_sift_down(theRoot);
}

/**
 * swap - Swap the values of two nodes
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 * Description: Swap the values of two nodes
 * Return: void
 */
void swap(heap_t **a, heap_t **b)
{
	int temp;
	heap_t *temp_node;

	temp = (*a)->n;
	temp_node = *a;
	(*a)->n = (*b)->n;
	*a = *b;
	(*b)->n = temp;
	*b = temp_node;
}

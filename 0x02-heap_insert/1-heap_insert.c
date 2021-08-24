#include "binary_trees.h"

/**
 * heap_insert - heap_t **root int value
 * @root: the root node
 * @value: the value
 * description: function that inserts a value into a Max Binary Heap
 * Return: pointer to the inserted node, or NULL on failure
 */ 

heap_t *heap_insert(heap_t **root, int value);
{
	/*create node with value assigned*/
	heap_t *newby = binary_tree_node(*root, value);

	/*If the address os root is NULL, the created node become the root node*/
	if(!(*root))
		return(*root = newby);

}

**
** description: Generate left child index of index passed in
**/
*size_t getLeftChild(int index)
*{
*	return (2 * index + 1);
*}
*/**
** description: Generate right child index of index passed in
**/
*size_t getRightChild(int index)
*{
*	return (2 * index + 2);
*}
*/**
** description: Generate parent index of index passed in
**/
*size_t getParent(int index)
*{
*	return ((index - 1) / 2);
*}
*/**
** swap - size_t i, size_t j
** @i: First indices
** @j: Second indices
** description: Swap data between parent node
**/
*void swap(size_t i, size_t j)
*{
*	size_t temp = heap[i];
*	heap[i] = heap[j];
*	heap[j] = temp;
*}
*/**
** getSiblings - int left, int right
** @left: bool has left
** @right: bool has right
** description: Checks to see if node has left or right child
** Return: 1 for true, 0 for false
**/
*size_t hasSibling(int index)
*{
*	int lftFlag = 0;
*	int rtFlag = 0;
*	if(getLeftChild(index) < heapSize)
*	{
*		lftFlag++;
*		continue;
*	}
*	if(getRightChild(index) < heapSize)
*	{
*		rtFlag++;
*		continue;
*	}
*}
*/ iParent(i)     = floor((i-1) / 2) where floor functions map a real number to the smallest leading integer.
//   iLeftChild(i)  = 2*i + 1
//   iRightChild(i) = 2*i + 2
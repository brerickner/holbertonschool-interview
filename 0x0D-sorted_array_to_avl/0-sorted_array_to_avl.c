#include "binary_trees.h"
/**
 * binary_tree_node - binary_tree_t *parent, int value
 * @parent: root node
 * @value: value contained in node
 * description: function that creates a binary tree node
 * Return: Pointer to new node. Else NULL
 */

avl_t *binary_tree_node(binary_tree_t *parent, int value)
{
	avl_t *newNode = malloc(sizeof(avl_t));

	if (newNode == NULL)
		return (NULL);

/* create the new node with goodies */
	newNode->parent = parent;
	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return (newNode);
}

/**
* sorted_array_to_avl - int *array, size_t size
* @array: pointer to first element of the array to be converted
* @size: size_t value representing number of elements in the array
* description: program that creates an AVL tree from an array
* that has no duplicate values. 3 functions max. Functions cannot rotate.
* Return: pointer to root node of newly created AVL tree or NULL if it fails.
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (binary_tree_node(NULL, array[0]));
}

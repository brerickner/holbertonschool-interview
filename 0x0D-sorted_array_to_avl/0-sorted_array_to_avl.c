#include "binary_trees.h"
/**
 * binary_tree_node - binary_tree_t *parent, int indexer
 * @array: the array
 * @size: the size
 * @parent: root node
 * @indexer: indexer contained in node
 * description: function that creates a binary tree node
 * Return: Pointer to new node. Else NULL
 */

avl_t *binary_tree_node(int *array, avl_t *parent, int indexer, size_t size)
{
	avl_t *newNode = malloc(sizeof(avl_t));

	if (newNode == NULL)
		return (NULL);

	if (indexer > (int)size)
		return (NULL);

/* create the new node with goodies */
	newNode->parent = parent;
	newNode->n = array[(indexer + size) / 2];
	newNode->left = (
					binary_tree_node(
						array,
						newNode,
						0,
						(((indexer + size) / 2) - 1))
					);
	newNode->right = (
					binary_tree_node(
						array,
						newNode,
						(((indexer + size) / 2) + 1),
						0)
					);
	return (newNode);
}

/**
* sorted_array_to_avl - int *array, size_t size
* @array: pointer to first element of the array to be converted
* @size: size_t indexer representing number of elements in the array
* description: program that creates an AVL tree from an array
* that has no duplicate values. 3 functions max. Functions cannot rotate.
* Return: pointer to root node of newly created AVL tree or NULL if it fails.
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size < 1)
		return (NULL);

	return (binary_tree_node(array, NULL, 0, size - 1));
}

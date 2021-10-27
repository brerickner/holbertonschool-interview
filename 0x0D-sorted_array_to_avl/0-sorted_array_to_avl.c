#include "binary_trees.h"

void _binary_tree_delete(binary_tree_t *tree)
{
  if (tree == NULL)
    return;
  _binary_tree_delete(tree->left);
  _binary_tree_delete(tree->right);
  free(tree);
}

/**
 * avl_t - int *array, avl_t_t *parent, int value
 * @parent: root node
 * @value: value contained in node
 * description: function that creates binary tree nodes recursively through AVL
 * Return: Pointer to new node. Else NULL
 */

avl_t *binary_tree_node(int *array, avl_t *parent, int begin, int end)
{
	avl_t *newNode = malloc(sizeof(avl_t));
	int value;

	if (newNode == NULL)
		return (NULL);
	value = (begin + end) / 2;
	if (begin > end)
		return (NULL);
	/* create the new node with goodies */
	newNode->parent = parent;
	newNode->n = array[value];
	newNode->left = binary_tree_node(array, newNode, begin, (value - 1));
	newNode->right = binary_tree_node(array, newNode, (value + 1), end);

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
	
	return(binary_tree_node(array, NULL, 0, size - 1));
}

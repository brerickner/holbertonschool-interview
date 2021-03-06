#include "binary_trees.h"

/**
* binary_tree_node - binary_tree_t *parent, int value
* @parent: parent node
* @value: int
* description: function that creates a binary tree node
* Return: pointer to the new node, or NULL on failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/* Declare memory */
	binary_tree_t *newNode = malloc(sizeof(binary_tree_t));

	/* malloc check */
	if (newNode == NULL)
		return (NULL);

	/* creates the new node with goodies */
	newNode->parent = parent;
	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return (newNode);
}

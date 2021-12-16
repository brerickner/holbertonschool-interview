#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


/*Basic Binary Tree*/

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;
typedef struct binary_tree_s binary_tree_t;

/*Max Binary Heap*/
typedef struct binary_tree_s heap_t;

int heap_extract(heap_t **root);
void binary_tree_print(const binary_tree_t *tree);
void heap_sift_down(binary_tree_t *root);
void swap(heap_t **a, heap_t **b);


#endif /* _BINARY_TREES_H_ */

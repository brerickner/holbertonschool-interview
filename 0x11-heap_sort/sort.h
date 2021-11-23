#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
int max_heapify(int *array, int n, int i, int j, int k);
void downheap(int *array, size_t size, int i);

#endif /* SORT_H */

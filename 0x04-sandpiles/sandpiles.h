#ifndef SANDPILES_H
#define SANDPILES_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef N
#undef N
#endif
#define N 3

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
static void print_grid(int grid[3][3]);
int stability_alert(int grid1[3][3], int grid2[3][3]);

#endif /* SANDPILES_H */

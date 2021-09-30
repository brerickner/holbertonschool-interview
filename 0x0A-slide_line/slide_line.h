#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


int slide_line(int *line, size_t size, int direction);
void swapski(int *line, int zero, int direction);
void makin_moves(int *line, int size, int direction);
void squish(int *line, int size, int direction);

#define SLIDE_LEFT 1
#define SLIDE_RIGHT -1

#endif /* SLIDE_LINE_H */

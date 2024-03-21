#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <stdio.h>

typedef struct Node {
    unsigned int label;
    struct Node **neighbours;
    int numberOfNeighbours;
    int color;
} Node;

typedef struct Graph {
    Node **nodes;
    int numberOfNodes;
} Graph;

#endif
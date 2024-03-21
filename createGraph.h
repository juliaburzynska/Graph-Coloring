#ifndef STWORZGRAF_H
#define STWORZGRAF_H

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

Graph *createGraph();

Node *addNode(Graph *g, unsigned int label);

void removeNode(Graph *graph, unsigned int label);

void addEdge(Graph *g, unsigned int label1, unsigned int label2);

void removeEdge(Graph *graph, unsigned int label1, unsigned int label2);

Node *findNode(Graph *graph, unsigned int label);

#endif



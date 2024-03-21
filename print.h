#ifndef WYPISYWANIE_H
#define WYPISYWANIE_H

#include <stdio.h>
#include "structures.h"
#include <string.h>
#include <stdlib.h>

#define size 5

void printLabelsToBinary(Graph *graph, char name[]);
void printColorsToTxt(Graph *graph, char name[]);
void printLabels(Graph *graph);
void printInstructionsToTxt(char name[]);
void printMenu(void);

#endif
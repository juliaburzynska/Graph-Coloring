#ifndef POLECENIA_H
#define POLECENIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#include "structures.h"
#include "createGraph.h"
#include "color.h"
#include "print.h"

int countColons(char *s);

int countCommas(char *s);

void removeWhitespaces(char *s);

void menu(char *instruction, Graph *g);

#endif


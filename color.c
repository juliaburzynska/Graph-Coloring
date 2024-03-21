#include "color.h"

void colorGraph(Graph *g) {
    for (int i = 0; i < g->numberOfNodes; i++) {
        Node *pNode = g->nodes[i];
        pNode->color = 0;
    }
    for (int i = 0; i < g->numberOfNodes; i++) {
        Node *current = g->nodes[i];
        for (int j = 0; j < current->numberOfNeighbours; j++) {
            if (current->color == current->neighbours[j]->color) {
                current->color++;
                j = 0;
                i = 0;
            }
        }
    }
}
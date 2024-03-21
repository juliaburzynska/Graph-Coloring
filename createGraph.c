#include "createGraph.h"

//funkcja tworząca graf
Graph *createGraph(void) {
    Graph *g;
    g = (Graph *) malloc(sizeof(Graph));
    if (g != NULL) {
        g->nodes = NULL;
        g->numberOfNodes = 0;
    } else puts("Memory for graph allocation exception.");
    return g;
}


Node *addNode(Graph *g, unsigned int label) {

    for (int i = 0; i < g->numberOfNodes; i++) {
        if (g->nodes[i]->label == label) {
            puts("Node already exists.");
            return NULL;
        }
    }

    Node *w;
    w = (Node *) malloc(sizeof(Node));
    if (w == NULL) {
        puts("Memory for node allocation exception.");
        return w;
    }
    w->label = label;
    w->neighbours = NULL;
    w->numberOfNeighbours = 0;


    g->numberOfNodes++;
    g->nodes = (Node **) realloc(g->nodes, g->numberOfNodes * sizeof(Node));
    if (g->nodes == NULL) {
        puts("Memory for node allocation exception.");
        return NULL;
    }
    g->nodes[g->numberOfNodes - 1] = w;

    return w;
}


void addEdge(Graph *g, unsigned int label1, unsigned int label2) {

    Node *a = findNode(g, label1);
    if (a == NULL) {
        printf("Edge not found. %d!\n", label1);
        return;
    }
    Node *b = findNode(g, label2);
    if (b == NULL) {
        printf("Node not found. %d!\n", label2);
        return;
    }


    for (int i = 0; i < a->numberOfNeighbours; i++) {
        if (a->neighbours[i] == b) {
            puts("Edge already exists.");
            return;
        }
    }

    a->numberOfNeighbours++;
    a->neighbours = (Node **) realloc(a->neighbours, a->numberOfNeighbours * sizeof(Node));
    if (a->neighbours == NULL) {
        puts("Memory for neighbour node allocation problem.");
        return;
    }
    a->neighbours[a->numberOfNeighbours - 1] = b;

    b->numberOfNeighbours++;
    b->neighbours = (Node **) realloc(b->neighbours, b->numberOfNeighbours * sizeof(Node));
    if (b->neighbours == NULL) {
        puts("Memory for neighbour node allocation problem.");
        return;
    }
    b->neighbours[b->numberOfNeighbours - 1] = a;
}


void removeNode(Graph *graph, unsigned int label) {

    Node *node = findNode(graph, label);
    if (node == NULL) {
        return;
    }

    int index = -1;
    for (int i = 0; i < graph->numberOfNodes; i++) {
        if (graph->nodes[i] == node) {
            index = i;
            break;
        }
    }
    for (int i = 0; i < node->numberOfNeighbours; i++) {
        removeEdge(graph, node->neighbours[i]->label, node->label);
    }

    if (index == -1) return;

    free(node->neighbours);
    free(node);

    for (int i = index; i < graph->numberOfNodes - 1; i++) {
        graph->nodes[i] = graph->nodes[i + 1];
    }

    graph->nodes = (Node **) realloc(graph->nodes, sizeof(Node *) * (graph->numberOfNodes - 1));
    graph->numberOfNodes--;
}


void removeEdge(Graph *graph, unsigned int label1, unsigned int label2) {

    Node *a = findNode(graph, label1);
    if (a == NULL) {
        printf("No node with given label. %d!\n", label1);
        return;
    }
    Node *b = findNode(graph, label2);
    if (b == NULL) {
        printf("No node with given label.  %d!\n", label2);
        return;
    }

    Node *node1 = NULL;
    Node *node2 = NULL;
    for (int i = 0; i < graph->numberOfNodes; i++) {
        if (graph->nodes[i]->label == a->label) {
            node1 = graph->nodes[i];
        }
        if (graph->nodes[i]->label == b->label) {
            node2 = graph->nodes[i];
        }
    }


    if (node1 == NULL || node2 == NULL) {
        puts("Edge does not exist.");
        return;
    }


    int found = 0;
    for (int i = 0; i < node1->numberOfNeighbours; i++) {
        if (node1->neighbours[i] == node2) {
            node1->neighbours[i] = node1->neighbours[node1->numberOfNeighbours - 1];
            node1->numberOfNeighbours--;
            found++;
            break;
        }
    }
    if (!found) {
        return;
    }

    for (int i = 0; i < node2->numberOfNeighbours; i++) {
        if (node2->neighbours[i] == node1) {
            node2->neighbours[i] = node2->neighbours[node2->numberOfNeighbours - 1];
            node2->numberOfNeighbours--;
            break;
        }
    }
}


Node *findNode(Graph *graph, unsigned int label) {
    if (graph == NULL) {
        printf("Pointer is NULL.\n");
        return NULL;
    }
    if (label == 0) {
        printf("Label is NULL.\n");
        return NULL;
    }
    for (int i = 0; i < graph->numberOfNodes; i++) {
        if (graph->nodes[i]->label == label) {
            return graph->nodes[i];
        }
    }
    return NULL;
}
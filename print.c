#include "print.h"


void printLabelsToBinary(Graph *graph, char name[]) {
    FILE *fp;

    char *name2 = (char *) calloc(1, strlen(name) + size);
    if (name2 != NULL) {
        strncat(name2, name, strlen(name));
        strcat(name2, ".bin");
        fp = fopen(name2, "wb");

        if (fp != NULL) {
            for (int i = 0; i < graph->numberOfNodes; i++) {
                fwrite(&graph->nodes[i]->label, sizeof(unsigned int), 1, fp);
            }
        } else puts("File opening exception");
        fclose(fp);
        free(name2);
    } else puts("Memory allocation exception");
}


void printColorsToTxt(Graph *graph, char name[]) {
    FILE *fp;

    char *name2 = (char *) calloc(1, strlen(name) + size);
    if (name2 != NULL) {
        strncat(name2, name, strlen(name));
        strcat(name2, ".txt");
        fp = fopen(name2, "w");

        if (fp != NULL) {
            for (int i = 0; i < graph->numberOfNodes; i++) {
                fprintf(fp, "Node %u - color %d\n", graph->nodes[i]->label, graph->nodes[i]->color);
            }
        } else puts("File opening exception");
        fclose(fp);
        free(name2);
    } else puts("Memory allocation exception");
}


void printLabels(Graph *graph) {
    printf("Graph nodes:\n");

    for (int i = 0; i < graph->numberOfNodes; i++) {
        printf("  Label: %u\n", graph->nodes[i]->label);
    }
}


void printInstructionsToTxt(char name[]) {
    FILE *fptr;

    char *name2 = (char *) calloc(1, strlen(name) + size);
    if (name != NULL) {
        strncat(name2, name, strlen(name));
        strcat(name2, ".txt");

        fptr = fopen(name, "w");
        if (fptr != NULL) {
            fprintf(fptr, "Exit - exit program\n\n");
            fprintf(fptr, "A: L - Add node, L - label\n\n");
            fprintf(fptr, "A: L1, L2 - Add edge, L1,L2 - labels of nodes between which the node is created\n\n");
            fprintf(fptr, "R: L - Remove node\n\n");
            fprintf(fptr, "R: L1, L2 - Remove edge\n\n");
            fprintf(fptr, "Colors name - Print color to txt file, name - name of the file\n\n");
            fprintf(fptr,
                    "Dump name - Print labels being used as a vertical vector to binary file, name - name of the file\n");
            fprintf(fptr, "List -  Print labels being used as a vertical vector\n\n");
            fprintf(fptr,
                    "Exec name - Calling a script in which the following lines contain the commands defined in the previous points");
        } else puts("File opening exception.");
        fclose(fptr);
        free(name2);
    } else puts("Memory allocation exception.");
}

void printMenu(void) {
    printf("Exit - exit program\n\n");
    printf("A: L - Add node, L - label\n\n");
    printf("A: L1, L2 - Add edge, L1,L2 - labels of nodes between which the node is created\n\n");
    printf("R: L - Remove node\n\n");
    printf("R: L1, L2 - Remove edge\n\n");
    printf("Colors name - Print color to txt file, name - name of the file\n\n");
    printf(
            "Dump name - Print labels being used as a vertical vector to binary file, name - name of the file\n");
    printf("List -  Print labels being used as a vertical vector\n\n");
    printf("Exec name - Calling a script in which the following lines contain the commands defined in the previous points\n");
}
#include "structures.h"
#include "createGraph.h"
#include "instructions.h"


int main() {
    Graph *g;
    g = createGraph();
    printMenu();
    for (;;) {
        char input[100];
        gets(input);
        menu(input, g);

    }
}


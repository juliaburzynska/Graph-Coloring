#include"instructions.h"

int countColons(char *string) {
    int colons = 0; //licznik dwukropkow
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == ':') {
            colons++;
        }
    }
    return colons;
}

int countCommas(char *string) {
    int commas = 0; //licznik przecinkow
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == ',') {
            commas++;
        }
    }
    return commas;
}

void removeWhitespaces(char *string) {
    int i, j = 0;
    for (i = 0; i < strlen(string); i++) {
        if (!isspace(string[i]) && !isblank(string[i])) {
            string[j++] = string[i];
        }
    }
    string[j] = '\0';
}


void menu(char *instruction, Graph *g) {
    removeWhitespaces(instruction);
    char command[10];
    unsigned int parameters[2];
    char parameter1[10];
    char parameter2[10];
    int count =0;
    int commas = countCommas(instruction);
    int colons = countColons(instruction);

    memset(command, 0, 10);

    if (commas == 0 && colons == 1) {
        if (instruction[1] == ':') {
            command[0] = instruction[0];
        } else {
            puts("Incorrect instruction.");
            return;
        }
        if (instruction[0] != 'A' && instruction[0] != 'R') {
            puts("Incorrect instruction.");
            return;
        }

        count = 2;
        if (instruction[count] == '0') {
            puts("Incorrect parameter");
            return;
        }
        while (instruction[count] != '\0') {
            if (instruction[count] > '9' || instruction[count] < '0') {
                puts("Incorrect parameter.");
                return;
            }
            parameter1[count - 2] = instruction[count];
            count++;
        }

        parameter1[count - 2] = '\0';

        if (parameter1[0] == 0) {
            puts("Lack of parameter.");
            return;
        }

        if (strlen(parameter1) > 10) {
            puts("Parameter too long.");
            return;
        }
        parameters[0] = (unsigned int)atoi(parameter1);

        if (instruction[0] == 'A') {
            addNode(g, parameters[0]);
            return;
        } else if (instruction[0] == 'R') {
            removeNode(g, parameters[0]);
            return;
        }

    } else if (commas == 1 && colons == 1) {

        if (instruction[1] == ':') {
            command[0] = instruction[0];
        } else {
            puts("Incorrect instruction.");
            return;
        }

        count = 2;
        if (instruction[count] == '0') {
            puts("Incorrect parameter.");
            return;
        }
        while (instruction[count] != ',') {
            if (instruction[count] > '9' || instruction[count] < '0') {
                puts("Incorrect parameter.");
                return;
            }
            parameter1[count - 2] = instruction[count];
            count++;
        }

        parameter1[count - 2] = '\0';
        if (parameter1[0] == 0) {
            puts("Lack of parameter");
            return;
        }

        if (strlen(parameter1) > 10) {
            puts("Parameter too long");
            return;
        }

        parameters[0] = (unsigned int)atoi(parameter1);

        count++;
        int i = count;
        if (instruction[count] == '0') {
            puts("Incorrect parameter.");
            return;
        }
        while (instruction[count] != '\0') {
            if (instruction[count] > '9' || instruction[count] < '0') {
                puts("Incorrect parameter.");
                return;
            }
            parameter2[count - i] = instruction[count];
            count++;
        }

        parameter2[count - i] = '\0';

        if (parameter2[0] == 0) {
            puts("Lack of parameter.");
            return;
        }

        if (strlen(parameter2) > 10) {
            puts("Parameter too long.");
            return;
        }

        parameters[1] = (unsigned int)atoi(parameter2);

        if (instruction[0] == 'A') {
            addEdge(g, parameters[0], parameters[1]);
            return;
        } else if (instruction[0] == 'R') {
            removeEdge(g, parameters[0], parameters[1]);
            return;
        }

    } else if (commas == 0 && colons == 0) {


        if (strlen(instruction) == 4 && strcmp("List", instruction) == 0) {
            printLabels(g);
            return;
        } else if (strlen(instruction) == 4 && strcmp("Exit", instruction) == 0) {
            abort();
        }

        for (int i = 0; i <= 3; i++) {
            command[i] = instruction[i];
        }

        if (strcmp("Exec", command) == 0) {
            count = 4;
            if (instruction[count] == '\0') {
                puts("No file title.");
                return;
            }

            printInstructionsToTxt(&instruction[count]);
            return;

        } else if (strcmp("Dump", command) == 0) {
            count = 4;
            if (instruction[count] == '\0') {
                puts("No file title.");
                return;
            }

            printLabelsToBinary(g, &instruction[count]);
            return;
        } else {
            for (int i = 4; i <= 5; i++) {
                command[i] = instruction[i];
            }

            if (strcmp("Colors", command) == 0) {
                count = 6;
                if (instruction[count] == '\0') {
                    puts("No file title.");
                    return;
                }
                colorGraph(g);
                printColorsToTxt(g, &instruction[count]);
                return;
            } else {
                puts("Incorrect instruction.");
                return;
            }
        }

    } else {
        puts("Incorrect instruction.");
        return;
    }

}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE 300000

int main(int argc, char **argv) {
    if (argc >= 3) {
        printf("Too many arguments\n");
        exit(1);
    } else if (argc < 2) {
        printf("No input file supplied\n");
        exit(1);
    }

    char cellArray[ARR_SIZE];
    char *pointer;
    char command, input;
    int jumpback;
    FILE *program = fopen(argv[1], "r");
    
    if (program == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    /* Initialize array to zero */
    memset(cellArray, 0, ARR_SIZE);

    /* Initialize pointer at first array position*/
    pointer = cellArray;
    while ((command = getc(program)) != EOF) {
        switch (command) {
        case '[':
            jumpback = ftell(program); /* Store bracket position for looping */
            if (*pointer == 0) while (getc(program) != ']');
            break;
        case ']':
            if (*pointer != 0) fseek(program, jumpback, SEEK_SET); /* Go back to matching bracket */
            break;
        case '>':
            pointer++;
            break;
        case '<':
            pointer--;
            break;
        case '+':
            (*pointer)++;
            break;
        case '-':
            (*pointer)--;
            break;
        case '.':
            putchar(*pointer);
            break;
        case ',':
            input = getchar();
            *pointer = input == EOF ? *pointer : input;
            break;    
        }
    }

    fclose(program);

    return 0;
}

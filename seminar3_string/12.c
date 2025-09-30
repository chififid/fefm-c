#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return 0;
    }
    char *word = argv[1];
    int times = atoi(argv[2]);
    for (int i = 0; i < times; i++) {
        printf("%s", word);
        if (i + 1 < times) printf(" ");
    }
    printf("\n");
    return 0;
}



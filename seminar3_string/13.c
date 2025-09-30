#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Error: Wrong number of arguments!\n");
        printf("Usage: ./calc <number> <operator> <number>\n");
        return 0;
    }

    long a, b;
    if (sscanf(argv[1], "%ld", &a) != 1 || sscanf(argv[3], "%ld", &b) != 1) {
        printf("Error: Operands should be integers!\n");
        return 0;
    }

    char op = argv[2][0];
    long result = 0;
    if (op == '+') {
        result = a + b;
    } else if (op == '-') {
        result = a - b;
    } else if (op == '*') {
        result = a * b;
    } else if (op == '/') {
        if (b == 0) {
            printf("Error: Division by zero!\n");
            return 0;
        }
        result = a / b;
    } else if (op == '%') {
        if (b == 0) {
            printf("Error: Division by zero!\n");
            return 0;
        }
        result = a % b;
    } else {
        printf("Error: Invalid operator!\n");
        return 0;
    }

    printf("%ld\n", result);
    return 0;
}



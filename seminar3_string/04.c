#include <stdio.h>

int main() {
    char a[256];
    char b[256];
    if (scanf("%255s %255s", a, b) != 2) {
        return 0;
    }

    int i = 0;
    int j = 0;
    while (a[i] != '\0' || b[j] != '\0') {
        if (a[i] != '\0') {
            putchar(a[i]);
            i++;
        }
        if (b[j] != '\0') {
            putchar(b[j]);
            j++;
        }
    }
    putchar('\n');

    return 0;
}



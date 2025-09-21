#include <stdio.h>

void bob(int n);
void alice(int n);

void alice(int n) {
    int new_n = n * 3 + 1;
    printf("Alice: %d\n", new_n);
    bob(new_n);
}

void bob(int n) {
    if (n == 1) {
        printf("Bob: %d\n", n);
        return;
    }
    if (n % 2 == 0) {
        printf("Bob: %d\n", n);
        bob(n / 2);
    } else {
        printf("Bob: %d\n", n);
        alice(n);
    }
}

int main() {
    alice(13);
    return 0;
}

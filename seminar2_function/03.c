#include <stdio.h>

void print_even(int start, int end) {
    for (int idx = start; idx <= end; idx++) {
        if (idx % 2 == 0) {
            printf("%d ", idx);
        }
    }
    printf("\n");
}

int main() {
    print_even(2, 15);
    print_even(1, 15);
    print_even(-7, 3);
    return 0;
}

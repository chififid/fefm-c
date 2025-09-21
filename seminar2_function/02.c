#include <stdio.h>

int is_even(int num) {
    if (num % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    printf("%d\n", is_even(90));
    printf("%d\n", is_even(91));
    return 0;
}

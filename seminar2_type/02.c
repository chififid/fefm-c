#include <stdio.h>

unsigned long long permutations(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }

    unsigned long long result = 1;
    for (int i = 0; i < k; i++) {
        result *= (n - i);
    }
    return result;
}

int main() {
    printf("%llu\n", permutations(5, 2));
    printf("%llu\n", permutations(20, 10));
    printf("%llu\n", permutations(30, 12));
    printf("%llu\n", permutations(60, 11));
    return 0;
}

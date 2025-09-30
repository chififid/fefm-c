#include <stdio.h>
#include <string.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    long long x = 0;
    long long y = 0;
    for (int i = 0; i < n; i++) {
        char dir[16];
        long long d;
        scanf("%15s %lld", dir, &d);
        if (strcmp(dir, "North") == 0) {
            y += d;
        } else if (strcmp(dir, "South") == 0) {
            y -= d;
        } else if (strcmp(dir, "East") == 0) {
            x += d;
        } else if (strcmp(dir, "West") == 0) {
            x -= d;
        }
    }
    printf("%lld %lld\n", x, y);
    return 0;
}



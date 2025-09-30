#include <stdio.h>

int main() {
    char s[1024];
    if (scanf("%1023s", s) != 1) {
        return 0;
    }

    long long sum = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            sum += s[i] - '0';
        }
    }

    printf("%lld\n", sum);
    return 0;
}



#include <stdio.h>

int is_palindrom(const char *s) {
    int left = 0;
    int right = 0;
    while (s[right] != '\0') {
        right++;
    }
    if (right == 0) {
        return 1;
    }
    right--;
    while (left < right) {
        if (s[left] != s[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int main() {
    char s[1024];
    if (scanf("%1023s", s) != 1) {
        return 0;
    }
    if (is_palindrom(s)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}



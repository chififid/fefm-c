#include <stdio.h>

void encrypt(char *str, int k) {
    if (k < 0) {
        k = 26 + (k % 26);
    }
    k = k % 26;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c >= 'A' && c <= 'Z') {
            int pos = c - 'A';
            pos = (pos + k) % 26;
            str[i] = (char)('A' + pos);
        } else if (c >= 'a' && c <= 'z') {
            int pos = c - 'a';
            pos = (pos + k) % 26;
            str[i] = (char)('a' + pos);
        }
    }
}

int main() {
    int k;
    char s[256];
    if (scanf("%d ", &k) != 1) {
        return 0;
    }
    scanf("%255[^\n]", s);
    encrypt(s, k);
    printf("%s\n", s);
    return 0;
}



#include <stdio.h>
#include <stddef.h>

void safe_strcpy(char dst[], size_t dst_size, const char src[]) {
    if (dst_size == 0) {
        return;
    }
    size_t i = 0;
    while (src[i] != '\0' && i + 1 < dst_size) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

int main() {
    char a[10] = "Mouse";
    char b[50] = "LargeElephant";
    safe_strcpy(a, 10, b);
    printf("%s\n", a);
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    char* result = (char*)malloc((len_a + len_b + 1) * sizeof(char));
    
    strcpy(result, a);
    strcat(result, b);
    
    return result;
}

int main() {
    char* result = concat("Hello", "World");
    printf("%s\n", result);
    
    free(result);
    return 0;
}

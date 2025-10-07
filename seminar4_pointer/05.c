#include <stdio.h>

void mult2(int* p, size_t n) {
    for (size_t i = 0; i < n; i++) {
        p[i] = p[i] * 2;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    mult2(arr, 5);
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

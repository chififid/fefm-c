#include <stdio.h>

void reverse(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    int temp;

    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int array1[] = {10, 20, 30, 40, 50};
    int size1 = 5;
    reverse(array1, size1);
    print_array(array1, size1);

    int array2[] = {60, 20, 80, 10};
    int size2 = 4;
    reverse(array2, size2);
    print_array(array2, size2);

    return 0;
}

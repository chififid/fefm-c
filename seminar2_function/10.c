#include <stdio.h>

#define MAX 3

void assign(float A[MAX][MAX], float B[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = B[i][j];
        }
    }
}

void print_matrix(float matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.1f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float matrix_b[MAX][MAX] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };
    float matrix_a[MAX][MAX];
    int n = 3;

    printf(" B \n");
    print_matrix(matrix_b, n);

    assign(matrix_a, matrix_b, n);

    printf("\n A \n");
    print_matrix(matrix_a, n);

    return 0;
}

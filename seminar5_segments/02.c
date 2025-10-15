#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float* get_geometric_progression(float a, float r, int n) {
    float* result = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        result[i] = a * pow(r, i);
    }
    return result;
}

int main() {
    float* progression = get_geometric_progression(1.0, 3.0, 10);
    
    for (int i = 0; i < 10; i++) {
        printf("%.0f ", progression[i]);
    }
    printf("\n");
    
    free(progression);
    return 0;
}

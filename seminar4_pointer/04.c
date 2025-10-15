#include <stdio.h>

void cube(float* px) {
    *px = *px * *px * *px;
}

int main() {
    float x = 3.0;
    printf("%.2f\n", x);
    cube(&x);
    printf("%.2f\n", x);
    return 0;
}


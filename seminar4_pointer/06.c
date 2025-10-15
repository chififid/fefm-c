#include <stdio.h>
#include <math.h>

int solve_quadratic(double a, double b, double c, double* px1, double* px2) {
    double eps = 1e-10;
    double d = b * b - 4 * a * c;
    
    if (d < -eps) {
        return 0;
    } else if (d < eps) {
        *px1 = -b / (2 * a);
        return 1;
    } else {
        double sqrt_d = sqrt(d);
        *px1 = (-b - sqrt_d) / (2 * a);
        *px2 = (-b + sqrt_d) / (2 * a);
        return 2;
    }
}

int main() {
    double x1, x2;
    int result = solve_quadratic(1, -5, 6, &x1, &x2);
    if (result == 2) {
        printf("x1 = %.2f, x2 = %.2f\n", x1, x2);
    } else if (result == 1) {
        printf("x = %.2f\n", x1);
    } else {
        printf("No real roots\n");
    }
    return 0;
}


#include <stdio.h>
#include <math.h>

#define STEP 1e-2
#define EPS 1e-10

double gamma_function(double x) {
    if (x <= 0) {
        return NAN;
    }

    double integral = 0.0;
    double t = 0.0;
    double term1, term2, area;

    while (1) {
        term1 = pow(t, x - 1) * exp(-t);
        t += STEP;
        term2 = pow(t, x - 1) * exp(-t);
        area = (term1 + term2) * STEP / 2.0;

        if (area < EPS && t > 100) {
            break;
        }
        integral += area;
    }

    return integral;
}

int main() {
    printf("%lf\n", gamma_function(2.0));
    printf("%lf\n", gamma_function(6.0));
    printf("%lf\n", gamma_function(20.0));
    printf("%lf\n", gamma_function(1.5));
    printf("%lf\n", gamma_function(2.5));
    printf("%lf\n", gamma_function(4.14159));
    return 0;
}

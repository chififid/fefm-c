#include <stdio.h>

float calculate_pi(int n) {
    float sum = 0.0;
    float sign = 1.0;
    for (int i = 1; i <= n; i++) {
        sum += sign / (2.0 * i - 1.0);
        sign *= -1.0;
    }
    return 4.0 * sum;
}

int main() {
    printf("%f\n", calculate_pi(1));
    printf("%f\n", calculate_pi(2));
    printf("%f\n", calculate_pi(10));
    printf("%f\n", calculate_pi(100));
    printf("%f\n", calculate_pi(10000));
    return 0;
}

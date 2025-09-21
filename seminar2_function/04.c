#include <stdio.h>

int sum_of_digits(int number) {
    int sum = 0;
    int remainder;

    while (number > 0) {
        remainder = number % 10;
        sum = sum + remainder;
        number = number / 10;
    }
    return sum;
}

int main() {
    printf("%d\n", sum_of_digits(123));
    printf("%d\n", sum_of_digits(55955));
    printf("%d\n", sum_of_digits(4));
    printf("%d\n", sum_of_digits(0));
    return 0;
}

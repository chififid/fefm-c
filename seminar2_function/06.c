#include <stdio.h>

long long trib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 0;
    if (n == 2) return 1;

    long long dp[40];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

int main() {
    printf("%lld\n", trib(1));
    printf("%lld\n", trib(5));
    printf("%lld\n", trib(20));
    printf("%lld\n", trib(35));
    printf("%lld\n", trib(38));
    return 0;
}

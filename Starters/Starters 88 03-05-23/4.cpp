#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = (1LL * result * base) % MOD;
        base = (1LL * base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> asteroids(N);
    for (int i = 0; i < N; i++) {
        std::cin >> asteroids[i].first >> asteroids[i].second;
    }

    std::sort(asteroids.begin(), asteroids.end());

    std::vector<int> dp(N + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        int k = 0;
        for (int j = i - 2; j >= 0; j--) {
            if (asteroids[j].second < asteroids[i - 1].second)
                k++;
            dp[i] = (dp[i] + (1LL * dp[j] * power(N, k)) % MOD) % MOD;
        }
        dp[i] = (dp[i] + power(N, i)) % MOD;
    }

    int result = (1LL * dp[N] * power(N, MOD - 2)) % MOD;
    std::cout << result << std::endl;

    return 0;
}

#include <bits/stdc++.h>
#include <vector>
#include <climits>

int N;
std::vector<std::vector<int>> wormholes;
std::vector<int> dp;

int solve(int universe, int space) {
    // Base case: reached the Nth universe
    if (universe == N - 1) {
        return 0;
    }

    // Check if the minimum time for this universe and space has already been calculated
    if (dp[universe] != -1) {
        return dp[universe];
    }

    int minTime = INT_MAX;
    for (int i = 0; i < wormholes[universe].size(); i++) {
        int nextSpace = wormholes[universe][i];
        int transitionTime = std::abs(nextSpace - space);

        // Recursively calculate the minimum time for the next universe
        int nextTime = solve(universe + 1, nextSpace);

        // Update the minimum time if the current wormhole leads to a faster time
        if (nextTime != -1) {
            minTime = std::min(minTime, transitionTime + nextTime);
        }
    }

    // Update the minimum time for this universe and space
    dp[universe] = (minTime != INT_MAX) ? minTime : -1;
    return dp[universe];
}

int main() {
    std::cin >> N; // Number of universes

    wormholes.resize(N);
    for (int i = 0; i < N; i++) {
        int K;
        std::cin >> K; // Number of wormholes in the ith universe
        wormholes[i].resize(K);
        for (int j = 0; j < K; j++) {
            std::cin >> wormholes[i][j]; // Position of each wormhole
        }
        sort(wormholes[i].begin(),wormholes[i].end());
    }

    // Initialize the dp array with -1 (indicating unset values)
    dp.resize(N, -1);

    int minTime = solve(0, 0); // Start from the first universe at space 0

    std::cout << minTime << std::endl;

    return 0;
}


/*
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

int main() {
    int N;
    std::cin >> N; // Number of universes

    std::vector<std::vector<int>> wormholes(N); // 0-indexed universes
    for (int i = 0; i < N; i++) {
        int K;
        std::cin >> K; // Number of wormholes in the ith universe
        wormholes[i].resize(K);
        for (int j = 0; j < K; j++) {
            std::cin >> wormholes[i][j]; // Position of each wormhole
        }
        sort(wormholes[i].begin(),wormholes[i].end());
    }

    std::vector<std::vector<int>> dp(N, std::vector<int>(101, INT_MAX)); // Initialize all values to infinity
    dp[0][0] = 0; // Starting from the 0th universe at space 0

    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < wormholes[i].size(); j++) {
            for (int k = 0; k < wormholes[i+1].size(); k++) {
                int transitionTime = std::abs(wormholes[i][j] - wormholes[i+1][k]);
                int nextSpace = wormholes[i+1][k];
                dp[i+1][nextSpace] = std::min(dp[i+1][nextSpace], dp[i][j] + transitionTime + std::abs(nextSpace - wormholes[i][j]));
            }
        }
    }

    int minTime = INT_MAX;
    for (int i = 0; i < wormholes[N-1].size(); i++) {
        minTime = std::min(minTime, dp[N-1][wormholes[N-1][i]]);
    }

    if (minTime == INT_MAX) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << minTime << std::endl;
    }

    return 0;
}
*/
/*
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

int main() {
    int N;
    std::cin >> N; // Number of universes

    std::vector<std::vector<int>> wormholes(N + 1); // 1-indexed universes
    for (int i = 1; i <= N; i++) {
        int K;
        std::cin >> K; // Number of wormholes in the ith universe
        wormholes[i].resize(K);
        for (int j = 0; j < K; j++) {
            std::cin >> wormholes[i][j]; // Position of each wormhole
        }
        sort(wormholes[i].begin(),wormholes[i].end());
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(101, INT_MAX)); // Initialize all values to infinity
    dp[1][0] = 0; // Starting from the 1st universe at space 0

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < wormholes[i].size(); j++) {
            for (int k = 0; k < 101; k++) {
                if (dp[i][k] != INT_MAX) {
                    for (int s = 0; s < wormholes[i+1].size(); s++) {
                        int transitionTime = std::abs(wormholes[i][j] - wormholes[i+1][s]);
                        int nextSpace = wormholes[i+1][s];
                        dp[i+1][nextSpace] = std::min(dp[i+1][nextSpace], dp[i][k] + transitionTime + std::abs(nextSpace - k));
                    }
                }
            }
        }
    }

    int minTime = INT_MAX;
    for (int i = 0; i < 101; i++) {
        minTime = std::min(minTime, dp[N][i]);
    }

    if (minTime == INT_MAX) {
        std::cout << -1 << std::endl;
    }else{

        std::cout << minTime << std::endl;
    }
    return 0;
}*/
/*
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

int main() {
    int N;
    std::cin >> N; // Number of universes

    std::vector<std::vector<int>> wormholes(N + 1); // 1-indexed universes
    for (int i = 1; i <= N; i++) {
        int K;
        std::cin >> K; // Number of wormholes in the ith universe
        wormholes[i].resize(K);
        for (int j = 0; j < K; j++) {
            std::cin >> wormholes[i][j]; // Position of each wormhole
        }
        sort(wormholes[i].begin(),wormholes[i].end());
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(101, INT_MAX)); // Initialize all values to infinity
    dp[1][0] = 0; // Starting from the 1st universe at space 0

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < wormholes[i].size(); j++) {
            for (int k = 0; k < wormholes[i+1].size(); k++) {
                int transitionTime = std::abs(wormholes[i][j] - wormholes[i+1][k]);
                int nextSpace = wormholes[i+1][k];
                dp[i+1][nextSpace] = std::min(dp[i+1][nextSpace], dp[i][j] + transitionTime + std::abs(nextSpace - j));
            }
        }
    }

    int minTime = INT_MAX;
    for (int i = 0; i < wormholes[N].size(); i++) {
        minTime = std::min(minTime, dp[N][wormholes[N][i]]);
    }

    if (minTime == INT_MAX) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << minTime << std::endl;
    }

    return 0;
}
*/
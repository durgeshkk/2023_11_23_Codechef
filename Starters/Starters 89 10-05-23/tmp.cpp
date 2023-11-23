#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include <vector>
#include <cmath>
using namespace std;

double mean(const vector<int>& v) {
    int n = v.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }
    return (double) sum / n;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> A(n);
    vector<int> B(m);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    // Step 1
    if (n == m) {
        A.push_back(k);
        B.push_back(k);
        n++;
        m++;
    }

    // Step 2
    if (n > m) {
        while (B.size() < n) {
            B.push_back(k);
            m++;
        }
    }

    // Step 3
    while (mean(A) <= mean(B)) {
        int y = ceil((mean(B) - mean(A)) * (n + 1) - accumulate(A.begin(), A.end(), 0));
        A.push_back(min(y, k));
        n++;
    }

    cout << A.size() << endl;
    return 0;
}

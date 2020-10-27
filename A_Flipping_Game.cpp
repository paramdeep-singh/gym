#include <bits/stdc++.h>

using namespace std;

int a[101], b[101], dp[101];

int main() {
    int n;
    cin >> n;

    int init_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i] ? -1 : 1;
        init_sum += a[i];
    }

    dp[0] = b[0];
    for (int i = 1; i < n; i ++) {
        dp[i] = max(b[i], b[i] + dp[i - 1]);
    }

    cout << init_sum + *max_element(dp, dp + n);
    return 0;
}
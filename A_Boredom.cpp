#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, a[N];
long long dp[N];
vector< pair<int, int> > comp_a;

void compress() {
    for (int i = 0; i < n; i ++) {
        int j = i + 1;
        while (j < n && a[j] == a[i]) {
            j ++;
        }
        comp_a.push_back(make_pair(a[i], j - i));
        i = j - 1;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);
    compress();

    dp[0] = 0;
    dp[1] = 1LL * comp_a[0].first * comp_a[0].second;

    for (int i = 2; i <= comp_a.size(); i ++) {
        dp[i] = dp[i - 1];
        long long points = 1LL * comp_a[i - 1].first * comp_a[i - 1].second;
        if (comp_a[i - 1].first == comp_a[i - 2].first + 1) {
            dp[i] = max(dp[i], points + dp[i - 2]);
        } else {
            dp[i] += points;
        }
    }

    cout << dp[comp_a.size()] << '\n';

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n, a[200010];

long long solve () {
    long long ans = 0;
    for (int i = 0; i < n; i ++) {
        int mx = a[i];
        int j = i + 1;
        while (j < n && (long long) a[i] * a[j] > 0) {
            mx = max(mx, a[j]);
            j ++;
        }
        i = j - 1;
        ans += mx;
    }
    return ans;
}

int main() {
    int tt;
    scanf("%d", &tt);

    while (tt --) {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
        }
        cout << solve() << '\n';
    }

    return 0;
}
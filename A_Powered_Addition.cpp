#include <bits/stdc++.h>

using namespace std;

int maxBit(int val) {
    return 32 - __builtin_clz(val);
}

int main() {
    int tt;
    scanf("%d", &tt);

    while (tt --) {
        int n;
        scanf("%d", &n);

        int ans = 0;
        int maxSoFar = -1000000009;

        for (int i = 0; i < n; i ++) {
            int x; scanf("%d", &x);
            if (x < maxSoFar) {
                int incrementRequired = maxSoFar - x;
                ans = max(ans, maxBit(incrementRequired));
            } else {
                maxSoFar = x;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
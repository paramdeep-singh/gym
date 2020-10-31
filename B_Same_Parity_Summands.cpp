#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    scanf("%d", &tt);

    while (tt --) {
        int n, k;
        scanf("%d %d", &n, &k);

        int lastTerm = n - (k - 1);
        if (n >= k && lastTerm % 2 && lastTerm > 0) {
            printf("YES\n");
            for (int i = 0; i < k - 1; i ++) {
                printf("1 ");
            }
            printf("%d\n", lastTerm);
            continue;
        }

        lastTerm = n - 2 * (k - 1);
        if (n >= 2 * k && lastTerm % 2 == 0 && lastTerm > 0) {
            printf("YES\n");
            for (int i = 0; i < k - 1; i ++) {
                printf("2 ");
            }
            printf("%d\n", lastTerm);
            continue;
        } 

        printf("No\n");
    }

    return 0;
}
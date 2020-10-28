#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int tt;
    scanf("%d", &tt);
 
    while (tt --) {
        int n, x;
        scanf("%d %d", &n, &x);
 
        int o = 0;
        for (int i = 0; i < n; i ++) {
            int v; scanf("%d", &v);
            o += (v & 1);
        }
        int e = n - o;
 
        if (!o) {
            printf("No\n");
            continue;
        }
        o --; x --;

        x -= 2 * min(x / 2, o / 2) + e;
        if (x <= 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
 
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    scanf("%d", &tt);

    while (tt --) {
        int n, k;
        scanf("%d %d", &n, &k);

        int mul = ceil(k / (double) (n - 1)) - 1; 
        printf("%d\n", mul + k);
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int canPair(int boySkill, int girlSkill) {
    return abs(boySkill - girlSkill) < 2;
}

int main() {
    int boysCount, boySkill[101];

    scanf("%d", &boysCount);
    for (int i = 0; i < boysCount; i ++) {
        scanf("%d", &boySkill[i]);
    }

    int girlsCount, girlSkill[101];
    scanf("%d", &girlsCount);
    for (int i = 0; i < girlsCount; i ++) {
        scanf("%d", &girlSkill[i]);
    }

    sort(boySkill, boySkill + boysCount);
    sort(girlSkill, girlSkill + girlsCount);

    int ans = 0;
    int girlPtr = 0;
    for (int i = 0; i < boysCount; i ++) {
        while (
            girlPtr < girlsCount &&
            !canPair(boySkill[i], girlSkill[girlPtr]) && 
            girlSkill[girlPtr] < boySkill[i]
        ) {
            girlPtr ++;
        }
        if (canPair(boySkill[i], girlSkill[girlPtr])) {
            ans ++;
            girlPtr ++;
        }
    }

    printf("%d", ans);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    scanf("%d", &tt);

    map<int, pair<char, char> > mp;
    mp[0] = pair<char, char>('0', '0');
    mp[1] = pair<char, char>('0', '1');

    while (tt --) {
        int n;
        scanf("%d", &n);

        string s;
        cin >> s;

        string ans1, ans2;
        bool firstBigger = false;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] != '2') {
                char c1 = mp[s[i] - '0'].first;
                char c2 = mp[s[i] - '0'].second;
                if (!firstBigger && c2 > c1) {
                    swap(c1, c2);
                }
                ans1 += c1;
                ans2 += c2;
                firstBigger |= c1 > c2;
            } else {
                if (firstBigger) {
                    ans1 += '0';
                    ans2 += '2';
                } else {
                    ans1 += '1';
                    ans2 += '1';
                }
            }
        }

        cout << ans1 << endl << ans2 << endl;
    }

    return 0;
}
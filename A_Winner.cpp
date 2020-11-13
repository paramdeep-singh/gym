#include <bits/stdc++.h>

using namespace std;

map<string, vector<pair<int, int> > > mp;

int storePlayerScore(string playerName, int score, int round) {
    int storedScore;
    if (mp[playerName].size() == 0) {
        storedScore = score;
    } else {
        int lastScore = mp[playerName][mp[playerName].size() - 1].first;
        storedScore = lastScore + score;
    }
    mp[playerName].push_back(make_pair(storedScore, round));
    return storedScore;
}

int getFirstRoundForAtLeastWinningScore(string playerName, int winningScore) {
    for (auto const& playerScoreDetails: mp[playerName]) {
        if (playerScoreDetails.first >= winningScore) {
            return playerScoreDetails.second;
        }
    }
    return -1;
}

string getWinnerName(int winningScore) {
    string winnerName;
    int leastRound = 1001;
    for (auto const& playerDetails : mp) {
        string playerName = playerDetails.first;
        if (mp[playerName][mp[playerName].size() - 1].first == winningScore) {
            int firstRoundToGetAtLeastWinningScore = 
                getFirstRoundForAtLeastWinningScore(playerName, winningScore);
            if (firstRoundToGetAtLeastWinningScore < leastRound) {
                winnerName = playerName;
                leastRound = firstRoundToGetAtLeastWinningScore;
            }
        }
    }
    return winnerName;
}

int getWinningScore() {
    int winningScore = -100000001;
    for (auto const& playerScoreDetails: mp) {
        vector< pair<int, int> > playerScores = playerScoreDetails.second;
        int lastScore = playerScores[playerScores.size() - 1].first;
        winningScore = max(winningScore, lastScore);
    }
    return winningScore;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i ++) {
        string s; cin >> s; 
        int score; scanf("%d", &score);
        
        int storedScore = storePlayerScore(s, score, i);
    }
    
    int winningScore = getWinningScore();

    cout << getWinnerName(winningScore) << '\n';
    return 0;
}
//PROBLEM LINK : https://leetcode.com/problems/coin-change/

//NOTE : There exist more optimized solution...!!


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int m = amount;
        int cc[n + 1][m + 1];
        for (int i = 0; i <= m; i++) {
            cc[0][i] = INT_MAX - 1;
        }

        for (int i = 0; i <= n; i++) {
            cc[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (coins[i - 1] > j)
                    cc[i][j] = cc[i - 1][j];
                else {
                    cc[i][j] = min(cc[i - 1][j], 1 + cc[i][j - coins[i - 1]]);
                }
            }
        }
        return cc[n][m] == INT_MAX - 1 ? -1 : cc[n][m];
    }
};
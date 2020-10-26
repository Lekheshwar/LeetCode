//  QUESTION LINK : https://leetcode.com/problems/champagne-tower/

class Solution {
public:
    double dp[101][101];
    double champagneTower(int poured, int query_row, int query_glass) {
        dp[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                double of = (dp[i][j] - 1.0) / 2.0;
                if (of > 0) {
                    dp[i + 1][j] += of;
                    dp[i + 1][j + 1] += of;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};
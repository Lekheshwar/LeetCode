// QUESIION LINK : https://leetcode.com/problems/stone-game-v/



class Solution {
public:
    int dp[501][501];
    int prefixSum[501];

    int helper(vector<int>& s, int l, int r) {

        if (l >= r) return 0; // BASE case

        if (dp[l][r] != -1)return dp[l][r]; // Return pre commputed sub-problem.

        int ans = INT_MIN;

        for (int i = 0; i < r - l; i++) { // You can only break the array at l+0, l+1, l+2,.....r-1 th index.

            int L = prefixSum[l + i + 1] - prefixSum[l];
            int R = prefixSum[r + 1] - prefixSum[l + i + 1];

            if (L < R) {
                int temp = dp[l][l + i] == -1 ? helper(s, l, l + i) : dp[l][l + i];
                ans = max(ans, L + temp);
            }
            else if (R < L) {
                int temp = dp[l + i + 1][r] == -1 ? helper(s, l + i + 1, r) : dp[l + i + 1][r];
                ans = max(ans, temp + R);
            }
            else {
                int temp1 = dp[l][l + i] == -1 ? helper(s, l, l + i) : dp[l][l + i];
                int temp2 = dp[l + i + 1][r] == -1 ? helper(s, l + i + 1, r) : dp[l + i + 1][r];
                ans = max(ans, L + max(temp1, temp2));
            }
        }
        return dp[l][r] = ans;
    }


    int stoneGameV(vector<int>& stoneValue) {
        int ans = INT_MIN;
        memset(dp, -1, sizeof dp);
        int n = stoneValue.size();

        prefixSum[0] = 0;  // Prefix sum is used to optimize the intermediate Range Sum...

        for (int i = 0; i < n; i++)prefixSum[i + 1] = prefixSum[i] + stoneValue[i];

        ans = helper(stoneValue, 0, n - 1);

        return ans;
    }
};
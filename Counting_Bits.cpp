class Solution {
public:
    vector<int> countBits(int nums) {
        vector<int> dp(nums + 1, 0);
        dp[0] = 0;

        for (int i = 1; i <= nums; i++) {
            if ((i & (i - 1)) == 0) {
                cout << i << " ";
                dp[i] = 1;
            }
            else if (i & 1 == 1) {
                dp[i] = dp[i >> 1] + 1;
            }
            else {
                dp[i] = dp[i >> 1];
            }
        }
        return dp;
    }
};
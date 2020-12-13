// Watch Tech Dose YT for explainatio.....

int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n+2, 0));
        vector<int> a;
        a.push_back(1);
        for(auto x : nums)a.push_back(x);
        a.push_back(1);
        
        for(int sz = 1; sz <= n; sz++){
            for(int left = 1; left <= n - sz + 1; left++){
                int right = left + sz - 1;
                for(int i = left; i <= right; i++){
                    dp[left][right] = max(dp[left][right], 
                                         a[left - 1] * a[i] * a[right + 1]+
                                         dp[left][i - 1] + dp[i + 1][right]);
                }
            }
        }
        return dp[1][n];
    }

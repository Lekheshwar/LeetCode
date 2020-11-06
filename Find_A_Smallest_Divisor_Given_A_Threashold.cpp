// QUESTION LINK : https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3521/


class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        int n = nums.size();
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        while (l < r) {
            int mid = l + (r - l) / 2;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += ceil((double)nums[i] / (double)mid);
            }
            if ( sum <= t ) {
                r = mid;
            }
            else
                l = mid + 1;
        }
        return l;
    }
};
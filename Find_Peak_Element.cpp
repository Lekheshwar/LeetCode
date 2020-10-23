// QUESTION LINK : https://leetcode.com/explore/learn/card/binary-search/126/template-ii/948/

/*
class Solution {
public:
    const long long NINF = LLONG_MIN;
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;

            long long prev = mid - 1  >= 0 ? nums[mid - 1] : NINF;
            long long next = mid + 1 < nums.size() ? nums[mid + 1] : NINF;

            if (nums[mid] > prev && nums[mid] > next) {
                return mid;
            }
            else if (nums[mid] > prev) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left == right ? left : -1;
    }
};
*/



// BETTER APPROACH

// NOTE : Can also be done recursively

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            }
            else
                left = mid + 1;
        }

        return left;
    }
};
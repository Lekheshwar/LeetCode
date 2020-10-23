//  QUESTION LINK : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
  int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    int n = right + 1;

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > nums[mid + 1]) {
        return nums[mid + 1];
      }
      if (nums[left] <= nums[mid]) {
        left = mid + 1;
      }
      else
        right = mid - 1;
    }
    return nums[(left + 1) % n];
  }
};
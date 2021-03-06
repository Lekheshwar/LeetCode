// QUESION LINK : https://leetcode.com/explore/learn/card/binary-search/135/template-iii/944/

// NOTE : Recursive solution preforms the search in a single pass....

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int first = -1, last = -1;

        // FIRST TARGET
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;
            }
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        // LAST TARGET
        if (first == -1) return { -1, -1}; // No point in doing the search again if target dosen't exit.....
        left = first;
        right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;
            }
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return {first, last};
    }
};




/*
class Solution {
public:

    int findLeft(vector<int>& nums,int target, int start, int end){
        if(start > end)return -1;
        if(start == end) return nums[start] == target ? start : -1;

        int mid = start + (end - start) / 2;
        if(nums[mid] == target){
            int k = findLeft(nums, target, start, mid - 1);
            return k == -1 ? mid : k;
        }
        else
            return findLeft(nums, target, mid+1, end);
    }

    int findRight(vector<int>& nums,int target, int start, int end){
        if(start > end)return -1;
        if(start == end) return nums[start] == target ? start : -1;

        int mid = start + (end - start) / 2;
        if(nums[mid] == target){
            int k = findRight(nums, target, mid + 1, end);
            return k == -1 ? mid : k;
        }
        else
            return findRight(nums, target, start, mid - 1);
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right){
           int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                int start = findLeft(nums, target, left, mid - 1);
                int end = findRight(nums, target, mid + 1, right);
                start = start == -1 ? mid : start;
                end = end == -1 ? mid : end;
                return {start, end};
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return {-1, -1};
    }
};

*/
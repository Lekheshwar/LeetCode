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

    int findLeft(vector<int>& nums,int target, int s, int e){
        if(s > e)return -1;
        if(s == e) return nums[s] == target ? s : -1;
        int mid = s + (e - s) / 2;
        if(nums[mid] == target){
            int k = findLeft(nums, target, s, mid - 1);
            return k == -1 ? mid : k;
        }
        else
            return findLeft(nums, target, mid+1, e);
    }

    int findRight(vector<int>& nums,int target, int s, int e){
        if(s > e)return -1;
        if(s == e) return nums[s] == target ? s : -1;
        int mid = s + (e - s) / 2;
        if(nums[mid] == target){
            int k = findRight(nums, target, mid + 1, e);
            return k == -1 ? mid : k;
        }
        else
            return findRight(nums, target, s, mid - 1);
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)return {-1, -1};
        int l = 0;
        int r = n - 1;
        int mid;
        while(l <= r){
            mid = l + (r - l) / 2;
            if(nums[mid] == target){
                int start = findLeft(nums, target, l, mid - 1);
                int end = findRight(nums, target, mid + 1, r);
                start = start == -1 ? mid : start;
                end = end == -1 ? mid : end;
                return {start, end};
            }
            else if(nums[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return {-1, -1};
    }
};

*/
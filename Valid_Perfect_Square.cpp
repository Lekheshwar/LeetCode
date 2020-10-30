// QUESTION LINK : https://leetcode.com/explore/learn/card/binary-search/137/conclusion/978/

class Solution {
public:
	bool isPerfectSquare(int nums) {
		if (nums == 1)return true;
		int l = 2, r = nums >> 1;
		while (l <= r) {
			long long mid = l + (r - l) / 2;
			long long k = mid * mid;
			if (k == nums)return true;
			else if (k > nums)
				r = mid - 1;
			else
				l = mid + 1;
		}
		return false;
	}
};
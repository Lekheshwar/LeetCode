class Solution {
public:
    char nextGreatestLetter(vector<char>& s, char t) {
        if (s.back() <= t)return s[0];

        int l = 0, r = s.size() - 1;
        while (l  < r) {
            int mid = l + (r - l) / 2;
            if (s[mid] > t) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return s[l];

    }
};
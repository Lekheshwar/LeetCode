class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(), left = 0, right = n - 1;
        int idx = -1;

        // FINDING THE INDEX ;

        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x) {
                idx = mid;
                break;
            }
            else if (arr[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }

        if (idx == -1) {
            idx = abs(arr[left] - x) <= abs(arr[right] - x) ? left : right;
            idx = idx - 1 >= 0 && abs(arr[idx - 1] - x) <= abs(arr[idx] - x) ? idx - 1 : idx;
        }

        int start = idx - 1, end = idx + 1;
        k--;

        while (k--) {
            if (start >= 0 && end < n) {
                if (abs(arr[start] - x) <= abs(arr[end] - x))
                    start--;
                else
                    end++;
            }
            else if (start < 0)
                end++;
            else
                start--;
        }

        return vector<int>(arr.begin() + start + 1, arr.begin() + end);

    }
};
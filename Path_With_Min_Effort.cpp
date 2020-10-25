// QUESTION LINK : https://leetcode.com/contest/weekly-contest-212/problems/path-with-minimum-effort/

class Solution {
public:
    int v[101][101];
    bool helper(vector<vector<int>> &h, int m, int n, int k, int i, int j) {
        if (i == m && j == n) return true;
        v[i][j] = 1;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        int poss = false;

        for (int d = 0; d < 4; d++) {
            if (i + dx[d] < 0 || i + dx[d] > m || j + dy[d] < 0 || j + dy[d] > n) continue;
            if (abs(h[i][j] - h[i + dx[d]][j + dy[d]]) <= k && v[i + dx[d]][j + dy[d]] == 0)
                poss = poss || helper(h, m, n, k, i + dx[d], j + dy[d]);
        }
        return poss;
    }

    int minimumEffortPath(vector<vector<int>>& h) {

        int s = 0, e = INT_MAX, ans = INT_MAX;

        while (s <= e) {
            int m = s + (e - s) / 2;
            memset(v, 0, sizeof v);
            if (helper(h, h.size() - 1, h[0].size() - 1, m, 0, 0)) {
                ans = min(ans, m);
                e = m - 1;
            }
            else
                s = m + 1;
        }
        return ans;
    }
};
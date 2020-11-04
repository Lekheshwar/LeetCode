// QUESTION LINK : https://leetcode.com/explore/featured/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3519/


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if (n == 1)return {0};

        vector<int> leaves;
        vector<int> degree(n, 0);
        unordered_map<int, unordered_set<int>> adj;

        for (auto pair : edges) {
            adj[pair[0]].insert(pair[1]);
            adj[pair[1]].insert(pair[0]);

            degree[pair[0]]++;
            degree[pair[1]]++;
        }


        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) {
                leaves.push_back(i);
            }
        }

        while (n > 2) {
            vector<int> newLeaves;
            n = n - leaves.size();
            for (auto leaf : leaves) {
                for (auto padosi : adj[leaf]) {

                    adj[padosi].erase(leaf);
                    degree[padosi]--;

                    if (degree[padosi] == 1)
                        newLeaves.push_back(padosi);
                }
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};
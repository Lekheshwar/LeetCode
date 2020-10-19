class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {

        /*   BRUTE FORCE

        int n = A.size();
        unordered_set<int> visited;
        int ans = INT_MAX;
        int cnt = 0;

        //   Ath itr---
        for(int i = 0; i < n; i++){
            int k = A[i];
            if(visited.find(k) != visited.end()) continue;
            visited.insert(k);
            int j = 0;
            for(; j < n; j++){
                if(i == j) continue;
                if(A[j] != k && B[j] != k){
                    cnt = 0;
                    break;
                }
                if(A[j] == k) continue;
                if(B[j] == k){
                    cnt++;
                    continue;
                }
            }
            if(j == n){
                ans = min(ans, cnt);
                cnt = 0;
            }

        }
        visited.clear();
        // Bth itr--
        for(int i = 0; i < n ; i++){
             int k = B[i];
            if(visited.find(k) != visited.end()) continue;
            visited.insert(k);
            int j = 0;
            for(; j < n; j++){
                if(i == j) continue;
                if(A[j] != k && B[j] != k){
                    cnt = 0;
                    break;
                }
                if(B[j] == k) continue;
                if(A[j] == k){
                    cnt++;
                    continue;
                }
            }
            if(j == n){
                ans = min(ans, cnt);
                cnt = 0;
            }
        }

        if(ans == INT_MAX) return -1;
        return ans;
        */

        //  OPTIMAL  - O(N)

        int n = A.size();
        vector<int> freq(7, 0);

        for (int i = 0; i < n ; i++) {
            freq[A[i]]++;
            if (A[i] != B[i]) freq[B[i]]++;
        }

        int myNumber = 0;

        for (int i = 1; i <= 6; i++) {
            if (freq[i] == n) {
                myNumber = i;
                break;
            }
        }

        if (myNumber == 0) return -1;

        int cntA = 0;
        int cntB = 0;

        for (int i = 0; i < n; i++) {
            if (A[i] == myNumber)cntA++;
            if (B[i] == myNumber)cntB++;
        }

        return n - max(cntA, cntB);


    }
};
// QUESTION LINK : https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        for (int i = 0 ; i < a.size(); i++) {
            if (a[i] > 0) {
                st.push(i);
            }
            else {
                while (!st.empty()) {
                    if (a[st.top()] == abs(a[i])) {
                        a[st.top()] = 0;
                        a[i] = 0;
                        st.pop();
                        break;
                    }
                    else if (a[st.top()] > abs(a[i])) {
                        a[i] = 0;
                        break;
                    }
                    else {
                        a[st.top()] = 0;
                        st.pop();
                    }
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != 0)
                res.push_back(a[i]);
        }
        return res;
    }
};
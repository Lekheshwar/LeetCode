
// The following implementation O(n) time (3 Passes)

int largestRectangleArea(vector<int>& h) {
    int n = h.size();
    if (n == 0)return 0;
    stack<int> st;
    vector<int> left(n, 0), right(n , 0);

    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            left[i] = 0;
            st.push(i);
        }
        else {
            while (!st.empty() and h[st.top()] >= h[i])
                st.pop();
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
    }

    while (!st.empty())st.pop();

    for (int i = n - 1; i >= 0; i--) {
        if (st.empty()) {
            right[i] = n - 1;
            st.push(i);
        }
        else {
            while (!st.empty() and h[st.top()] >= h[i]) st.pop();
            right[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }
    }

    int mx = INT_MIN;
    for (int i = 0; i < n ; i++) {
        mx = max(mx, (right[i] - left[i] + 1) * h[i]);
    }
    return mx;
}


// The following code is space optimized.(Tricky as well)

int largestRectangleArea(vector<int>& h) {
    /*
        Just padd in an extra 0 in the end of the arr.
        It will handle the case if the array is exhausted and
        we still have elements left in the stack.
    */

    h.push_back(0);
    int n = h.size();
    stack<int> st;
    st.push(0);
    int mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        while (!st.empty() and h[st.top()] >= h[i]) {
            int temp = st.top();
            st.pop();
            /*
                The reason to multiply with i is, because the h[temp]
                is the smallest in the sub array [0, i).
            */
            mx = max(mx, h[temp] * (st.empty() ? i : (i - st.top() - 1)));
        }
        st.push(i);
    }
    return mx;
}
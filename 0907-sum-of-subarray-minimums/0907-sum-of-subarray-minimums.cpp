class Solution {
public:

    vector<int> findPreviousLess(vector<int>& arr) {
        int n = arr.size();
        vector<int> previousLess(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            // Remove values that are not strictly smaller.
            while (!st.empty() &&
                   arr[st.top()] >= arr[i]) {
                st.pop();
            }
            // A remaining index is the previous smaller boundary.
            if (!st.empty()) {
                previousLess[i] = st.top();
            }
            st.push(i);
        }
        return previousLess;
    }

    vector<int> findNextLessOrEqual(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextLessOrEqual(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            // Remove values that are strictly greater.
            while (!st.empty() &&
                   arr[st.top()] > arr[i]) {
                st.pop();
            }
            // A remaining index is the next valid boundary.
            if (!st.empty()) {
                nextLessOrEqual[i] = st.top();
            }
            st.push(i);
        }
        return nextLessOrEqual;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long mod = 1000000007;
 
        vector<int> previousLess = findPreviousLess(arr);
        vector<int> nextLessOrEqual = findNextLessOrEqual(arr);
 
        long long answer = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - previousLess[i];
            long long right = nextLessOrEqual[i] - i;
            long long contribution =
                (arr[i] * left) % mod;
            contribution =
                (contribution * right) % mod;

            answer = (answer + contribution) % mod;
        }
 
        return (int)answer;
    }
};
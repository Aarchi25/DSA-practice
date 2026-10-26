class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            while (!st.empty() && k > 0 &&
                   st.top() > s[i]) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string res = "";

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        // Remove leading zeros
        int i = 0;
        while (i < res.size() && res[i] == '0') {
            i++;
        }

        res = res.substr(i);

        return res.empty() ? "0" : res;
    }
};
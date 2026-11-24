class Solution {
public:
    bool isValid(string s) {
        string st;
        for (char c : s) {
            if (c == '(') st.push_back(')');
            else if (c == '[') st.push_back(']');
            else if (c == '{') st.push_back('}');
            else if (st.empty() || st.back() != c) return false;
            else st.pop_back();
        }
        return st.empty();
    }
};

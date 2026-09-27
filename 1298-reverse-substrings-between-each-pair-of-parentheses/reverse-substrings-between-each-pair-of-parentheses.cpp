class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> st;
        for (char c : s) {
            if (c != ')') {
                st.push_back(c);
            } else {
                vector<char> temp;
                while (!st.empty() && st.back() != '(') {
                    temp.push_back(st.back());
                    st.pop_back();
                }
                // pop '('
                if (!st.empty() && st.back() == '(') st.pop_back();
                // push reversed segment back
                for (char x : temp) st.push_back(x);
            }
        }
        return string(st.begin(), st.end());
    }
};
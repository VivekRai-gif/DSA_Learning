class Solution {
public:
    vector<string> result;

    void generate(string& current, int open, int close, int n) {
        if (open == n && close == n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            current.push_back('(');
            generate(current, open + 1, close, n);
            current.pop_back();
        }

        if (close < open) {
            current.push_back(')');
            generate(current, open, close + 1, n);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string current;
        generate(current, 0, 0, n);
        return result;
    }
};
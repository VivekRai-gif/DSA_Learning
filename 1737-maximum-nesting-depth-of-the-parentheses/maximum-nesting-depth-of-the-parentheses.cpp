class Solution {
public:
    int maxDepth(string s) {
        int currentDepth = 0;
        int maximumDepth = 0;

        for (char ch : s) {
            if (ch == '(') {
                currentDepth++;
                maximumDepth = max(maximumDepth, currentDepth);
            } 
            else if (ch == ')') {
                currentDepth--;
            }
        }

        return maximumDepth;
    }
};
///leetcode 1930.cpp
//21-11-2025
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int ans = 0;

        // For each character from 'a' to 'z'
        for(char ch = 'a'; ch <= 'z'; ch++) {
            int left = -1, right = -1;

            // Find first and last occurrence of ch
            for(int i = 0; i < n; i++) {
                if(s[i] == ch) {
                    if(left == -1) left = i;
                    right = i;
                }
            }

            // If we have at least two occurrences
            if(left != -1 && right != -1 && left < right) {
                // Collect distinct middle characters
                unordered_set<char> mid;
                for(int i = left + 1; i < right; i++) {
                    mid.insert(s[i]);
                }
                ans += mid.size();
            }
        }

        return ans;
    }
};

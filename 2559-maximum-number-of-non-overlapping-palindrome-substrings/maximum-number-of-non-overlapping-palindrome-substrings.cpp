class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
      
        // isPalindrome[i][j] = true if substring s[i...j] is a palindrome
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, true));
      
        // memo[i] stores the maximum number of non-overlapping palindromes 
        // starting from index i, -1 indicates not computed yet
        vector<int> memo(n, -1);
      
        // Build palindrome table using dynamic programming
        // Check all substrings from right to left, bottom to top
        for (int start = n - 1; start >= 0; --start) {
            for (int end = start + 1; end < n; ++end) {
                // A substring is palindrome if first and last characters match
                // and the inner substring is also a palindrome
                isPalindrome[start][end] = (s[start] == s[end]) && 
                                           isPalindrome[start + 1][end - 1];
            }
        }
      
        // Recursive function with memoization to find maximum palindromes
        function<int(int)> findMaxPalindromes = [&](int startIdx) -> int {
            // Base case: reached end of string
            if (startIdx >= n) {
                return 0;
            }
          
            // Return memoized result if already computed
            if (memo[startIdx] != -1) {
                return memo[startIdx];
            }
          
            // Option 1: Skip current position and check from next index
            int maxCount = findMaxPalindromes(startIdx + 1);
          
            // Option 2: Try to form palindromes starting at current position
            // Only consider palindromes of length at least k
            for (int endIdx = startIdx + k - 1; endIdx < n; ++endIdx) {
                if (isPalindrome[startIdx][endIdx]) {
                    // Include this palindrome and continue from next non-overlapping position
                    maxCount = max(maxCount, 1 + findMaxPalindromes(endIdx + 1));
                }
            }
          
            // Memoize and return result
            memo[startIdx] = maxCount;
            return maxCount;
        };
      
        // Start finding maximum palindromes from index 0
        return findMaxPalindromes(0);
    }
};

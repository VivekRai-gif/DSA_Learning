class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set<int> st;

        // Store all prefixes from arr1
        for (int num : arr1) {
            
            while (num > 0) {
                st.insert(num);
                num /= 10;
            }
        }

        int ans = 0;

        // Check prefixes in arr2
        for (int num : arr2) {
            
            while (num > 0) {
                
                if (st.count(num)) {
                    ans = max(ans, (int)log10(num) + 1);
                }

                num /= 10;
            }
        }

        return ans;
    }
};

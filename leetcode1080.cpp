class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int mod = 0;

        for (int b : nums) {
            mod = (mod * 2 + b) % 5; 
            ans.push_back(mod == 0);
        }

        return ans;
    }
};
//leetcode 1080
//date : 24-11-2025
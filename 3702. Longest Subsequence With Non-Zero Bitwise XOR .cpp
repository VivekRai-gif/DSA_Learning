class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            ans = ans ^ nums[i];

            if(nums[i] != 0)
            {
                count++;
            }
        }

        // Agar XOR non-zero hai,
        // saare elements le sakte hain
        if(ans != 0)
            return nums.size();

        // XOR zero hai, ek non-zero element remove karenge
        if(count > 0)
            return nums.size() - 1;

        // Saare elements zero hain
        return 0;
    }
};

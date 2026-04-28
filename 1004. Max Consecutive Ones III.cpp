class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeroCount = 0;
        for (int num : nums) {
           zeroCount += num ^ 1;
             if (zeroCount > k) {
                 zeroCount -= nums[left] ^ 1;
                left++;
            }
        }
    return nums.size() - left;
    }
};

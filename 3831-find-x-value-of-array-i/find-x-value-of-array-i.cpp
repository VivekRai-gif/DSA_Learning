class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> answer(k, 0);

        // dp[r] = number of subarrays ending at the previous index
        // whose product % k == r
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> nextDp(k, 0);
            int value = num % k;

            // Start a new subarray with only nums[i]
            nextDp[value]++;

            // Extend all previous subarrays
            for (int remainder = 0; remainder < k; remainder++) {
                int newRemainder =
                    (long long)remainder * value % k;

                nextDp[newRemainder] += dp[remainder];
            }

            // Every subarray ending here contributes to the answer
            for (int remainder = 0; remainder < k; remainder++) {
                answer[remainder] += nextDp[remainder];
            }

            dp = move(nextDp);
        }

        return answer;
    }
};
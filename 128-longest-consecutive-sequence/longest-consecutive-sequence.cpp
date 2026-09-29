class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());

        int longest = 0;

        for (int num : seen) {

            // Sequence ka starting point
            if (seen.find(num - 1) == seen.end()) {

                int current = num;
                int count = 1;

                // Aage consecutive numbers check karo
                while (seen.find(current + 1) != seen.end()) {
                    current++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};
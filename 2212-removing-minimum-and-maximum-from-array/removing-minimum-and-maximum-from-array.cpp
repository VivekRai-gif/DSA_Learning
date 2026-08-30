class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        // Find min and max
        int minVal = nums[0];
        int maxVal = nums[0];

        int minIndex = 0;
        int maxIndex = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] < minVal) {
                minVal = nums[i];
                minIndex = i;
            }

            if(nums[i] > maxVal) {
                maxVal = nums[i];
                maxIndex = i;
            }
        }

        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        // 1. Remove both from left
        int option1 = right + 1;

        // 2. Remove both from right
        int option2 = n - left;

        // 3. Remove one from left and one from right
        int option3 = (left + 1) + (n - right);

        return min({option1, option2, option3});
    }
};

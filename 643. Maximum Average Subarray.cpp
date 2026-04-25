class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum =0;
        for (int i=0;i<k;i++)
        {
            sum = sum + nums[i];
        }
        double maxsum = sum;
        int startidx=0;
        int lastidx = k;
        while (lastidx < nums.size())
        {
            sum = sum - nums[startidx];
            startidx ++;
            sum += nums[lastidx];
            lastidx ++;
            maxsum = max(maxsum,(double)sum);
        }
         return maxsum / k;
    }
};

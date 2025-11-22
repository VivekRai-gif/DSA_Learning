//leetcode 3190.cpp
//22-11-2025
class Solution 
{
    public:
        int minimumOperations (vector<int>& nums) {
        int i;
        int count=0;
        int n = nums.size();
        for(i=0;i<n;i++)
        {
            if(nums[i]%3!=0)    
            {
                count+=1;
            }
        }
        return count;
        }
};

//New Solution for leetcode 3190.cpp
        // class Solution {
        // public:
        //     int minimumOperations(vector<int>& nums) {
        //         int count = 0;
        //         for (int x : nums) {
        //             if (x % 3 != 0)
        //                 count++;
        //         }
        //         return count;
        //     }
        // };

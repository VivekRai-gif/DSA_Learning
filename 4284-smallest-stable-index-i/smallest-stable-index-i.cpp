class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
 

    for(int i = 0; i<nums.size(); i++){
        //i is the index 
        int maxi = nums[0];
        int mini = nums[i];
        
        for(int j =0;j<=i;j++)
           {  //find max element max(nums[0..i]) 
            maxi = max(maxi, nums[j]);
        }

        for(int j =i;j<=nums.size()-1;j++)
          {   //find min element min(nums[i..n - 1])
            mini = min(mini,nums[j]);
        }

        int result = maxi - mini;
        if(result <= k ){
             return i;
        }
    }
        return -1;
    }
};
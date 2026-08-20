class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
      vector<int> arr1;  
      vector<int> arr2;
           // First 2 elements
      arr1.push_back(nums[0]);
      arr2.push_back(nums[1]);
       // Remaining elements one-by-one
      for(int i =2; i<nums.size();i++)
      {
       if(arr1.back() > arr2.back())
        {   //nums [i]koo arr 1 me add
            arr1.push_back(nums[i]);
        }
        else {
            arr2.push_back(nums[i]);
        }
      }
         vector<int> result;
        //adding arr1
        for(int i = 0; i< arr1.size(); i++)
        {
            result.push_back(arr1[i]);
        }
        //adding array 2
        for(int i = 0; i< arr2.size(); i++)
        {
            result.push_back(arr2[i]);
        }
       
        return result;
      }
};
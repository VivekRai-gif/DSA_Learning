class Solution {
public:
int result = -1;
    int search(vector<int>& nums, int target) {
        for (int i =0; i< nums.size();i++)
        {
            if (nums[i]==target)
            {
              return i;
            }
        }
        return -1;
    }
};

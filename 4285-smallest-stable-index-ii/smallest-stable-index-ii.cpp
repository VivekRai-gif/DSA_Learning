class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        if (nums.empty()) {
            return -1;
        }
        vector<int> maxi;
        vector<int> mini(nums.size());

        //maxi vector from 0 to i
        int max_values = 0;

        for (int i = 0; i < nums.size(); i++) {
            max_values = max(max_values, nums[i]);
            maxi.push_back(max_values);
        }

        //mini vector from i to (n-1)
        int min_values = nums[nums.size() - 1];

        for (int i = nums.size() - 1; i >= 0; i--) {
            min_values = min(min_values, nums[i]);
            mini[i] = min_values;        
            }

        //now difference 
        for(int i = 0;i<nums.size(); i++){
            int diff = maxi[i] - mini[i];
            if(diff <= k){
                return i;
            }
        }
        return -1;
    }
};
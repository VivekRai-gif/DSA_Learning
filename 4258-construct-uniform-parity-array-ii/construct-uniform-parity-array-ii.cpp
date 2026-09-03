class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min = *min_element(begin(nums1),end(nums1));
        if(min % 2 != 0){//odd
            //possiple to make odd 
            return true;
        }
        //check we can make all even 
       for(int &num : nums1){
            if(num % 2 != 0){
                return false;
            }
       }
       return true;
    }
};
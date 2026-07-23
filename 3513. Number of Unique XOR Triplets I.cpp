class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 1;
        if (n == 2) return 2;

        int bits = 0;
        while (n) {
            bits++;
            //r8 shift
            n >>= 1;
        }
        //l8 shift
        return 1 << bits;
    }
};

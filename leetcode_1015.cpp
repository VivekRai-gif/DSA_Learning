//leetcode_1015.cpp
//date : 25-11-2025

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1; // repunit can't be divisible
        
        int rem = 0;
        for (int len = 1; len <= k; len++) {
            rem = (rem * 10 + 1) % k; // append 1
            if (rem == 0) return len; // divisible
        }
        return -1;
    }
};

// class Solution {
// public:
//     int sum = 0;
    
//     int maxSumDivThree(vector<int>& nums) {
//         int n = nums.size;
//         for (int i=0; i < n-1;i++)
//             {
//                 sum = nums[i]+nums[i+1];
//             }
//         if([sum % 3]==0)
//         {
//             return sum;
//         }

//     }
// };

        // class Solution {
        // public:
        //     int sum = 0;

        //     int maxSumDivThree(vector<int>& nums) {
        //         int n = nums.size();   // FIXED

        //         for (int i = 0; i < n - 1; i++)   // FIXED: avoid nums[i+1] out of range
        //         {
        //             sum = nums[i] + nums[i + 1]; // same format kept
        //         }

        //         if (sum % 3 == 0)   // FIXED: removed []
        //         {
        //             return sum;
        //         }

        //         return 0;   // FIXED: function must return something
        //     }
        // };
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int NEG_INF = numeric_limits<int>::min() / 4;
        // dp[r] = max sum with remainder r (mod 3)
        int dp[3] = {0, NEG_INF, NEG_INF};

        for (int x : nums) {
            int cur = x % 3;
            int tmp[3];
            tmp[0] = dp[0];
            tmp[1] = dp[1];
            tmp[2] = dp[2];

            // try to add x to each existing remainder class
            for (int r = 0; r < 3; ++r) {
                if (dp[r] != NEG_INF) {
                    int newR = (r + cur) % 3;
                    tmp[newR] = max(tmp[newR], dp[r] + x);
                }
            }

            // also consider starting a new subset with just x (already covered if dp[0]=0)
            // commit tmp to dp
            dp[0] = tmp[0];
            dp[1] = tmp[1];
            dp[2] = tmp[2];
        }

        return max(0, dp[0]); // dp[0] might be 0 or negative-inf; ensure non-negative result
    }
};



//new solution of questiion :correct one 
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int ans = accumulate(nums.begin(), nums.end(), 0);
        if(ans % 3 == 0) {
            return ans;
        }else {
            vector<int> p1, p2;
            for(int x : nums) {
                if(x % 3 == 1) p1.push_back(x);
                else if(x % 3 == 2) p2.push_back(x);
            }
            sort(p1.begin(), p1.end());
            sort(p2.begin(), p2.end());

            int sub = ans;
            if(ans % 3 == 2) { // we want a 2 or two 1's
                if(!p2.empty()) sub = min(sub, p2[0]);
                if(p1.size() >= 2) sub = min(sub, p1[0] + p1[1]);
            }else {
                if(!p1.empty()) sub = min(sub, p1[0]);
                if(p2.size() >= 2) sub = min(sub, p2[0] + p2[1]);
            }
            return ans - sub;
        }
    }
};
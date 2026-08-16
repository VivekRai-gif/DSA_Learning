class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {

        int cnt[3] = {0, 0, 0};

        // Count stones according to remainder
        for (int x : stones) {
            cnt[x % 3]++;
        }

        int zero = cnt[0];
        int one = cnt[1];
        int two = cnt[2];

        // Case 1: number of 0-remainder stones is even
        if (zero % 2 == 0) {
            return one > 0 && two > 0;
        }

        // Case 2: number of 0-remainder stones is odd
        return abs(one - two) > 2;
    }
};
// class Solution {
// public:
//     bool stoneGameIX(vector<int>& stones) {
//         int sum = 0;
//         //first alice
//         // for (int i = 0; i<stones.size(); i++)
//         // {   
//         int cnt[3] = {0};

//         for (int x : stones) {
//             cnt[x % 3]++;
//         }//alice tern
//             if(i%2 == 0)
//             {
//             sum += stones[i];
//             if (sum%3==0) return false;
//             }
//             //second bob
//             else{
//             sum += stones[i];
//             if (sum%3==0) return true;
//             }
//         }
//         return false;
//     }
// };
// //alice win -> true
// // bob win -> false
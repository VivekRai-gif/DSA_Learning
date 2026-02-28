// #include <vector>
// #include <algorithm> // for max
// #include <climits>   // for LLONG_MIN

// using namespace std;

// class Solution {
// public:
//     long long maxSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size(); // 1. Define n
//         long long maxVal = LLONG_MIN; // 2. Track the maximum found
//         bool found = false;

//         for (int i = 0; i < n; i++) 
//         {
//             long long currentSum = 0; // 3. Use a scalar variable, reset for every i
//             for (int j = i; j < n; j++) 
//             {
//                 currentSum += nums[j];

//                 // Check if divisible by k
//                 if (currentSum % k == 0) 
//                 {
//                     maxVal = max(maxVal, currentSum); // 4. Update max instead of returning
//                     found = true;
//                 }
//             }
//         }
        
//         if (found) return maxVal;
//         return -1;       
//     }
// };

// // // // // class Solution {
// // // // // // public:
// // // // // //     long long maxSubarraySum(vector<int>& nums, int k) {
// // // // // //         int sum=0;
// // // // // //         int N = nums.length;
// // // // // //         for (int i=0;i<N;i++)
// // // // // //         {
// // // // // //             sum=sum+num[i]+num[i+1];
// // // // // //         }
// // // // // //         if (sum % k == 0)
// // // // // //         {
// // // // // //             return sum;
// // // // // //         }
// // // // // //     }
// // // // // // };
// // // // // // class Solution {
// // // // // // public:
// // // // // //     long long maxSubarraySum(vector<int>& nums, int k) {
// // // // // //         long long sum = 0;
// // // // // //         int N = nums.size();

// // // // // //        for (int i = 0; i < N - 1; i++) {
// // // // // //     sum = sum + nums[i] + nums[i + 1];
// // // // // // }

// // // // // //         if (sum % k == 0) {
// // // // // //             return sum;
// // // // // //         }

// // // // // //         return -1; // or any default value you want
// // // // // //     }
// // // // // // };
// // // // // class Solution {
// // // // // public:
// // // // //     long long maxSubarraySum(vector<int>& nums) {
// // // // //         long long current = nums[0];
// // // // //         long long best = nums[0];

// // // // //         for (int i = 1; i < nums.size(); i++) {
// // // // //             // either extend previous subarray or start new
// // // // //             current = max((long long)nums[i], current + nums[i]);
// // // // //             best = max(best, current);
// // // // //         }

// // // // //         return best;
// // // // //     }
// // // // // };
// // // // #include <vector>
// // // // #include <algorithm>
// // // // #include <climits>

// // // // class Solution {
// // // // public:
// // // //     long long maxSubarraySum(vector<int>& nums) {
// // // //         if (nums.empty()) return 0; // or return LONG_MIN

// // // //         long long current = nums[0];
// // // //         long long best = nums[0];

// // // //         for (int i = 1; i < nums.size(); i++) {
// // // //             current = max((long long)nums[i], current + nums[i]);
// // // //             best = max(best, current);
// // // //         }

// // // //         return best;
// // // //     }
// // // // };
// // // class Solution {
// // // public:
// // //     long long maxSubarraySum(vector<int>& nums, int k) {
// // //         long long current = nums[0];
// // //         long long best = nums[0];

// // //         for (int i = 1; i < nums.size(); i++) {
// // //             current = max((long long)nums[i], current + nums[i]);
// // //             best = max(best, current);
// // //         }

// // //         return best;
// // //     }
// // // };
// // long long maxSubarraySum(vector<int>& nums, int k) {
// //     int n = nums.size();
// //     long long ans = LLONG_MIN;

// //     for (int i = 0; i < n; i++) {
// //         long long sum = 0;
// //         for (int j = i; j < n; j++) {
// //             sum += nums[j];
// //             int len = j - i + 1;
// //             if (len % k == 0) ans = max(ans, sum);
// //         }
// //     }
// //     return ans;
// // }
class Solution {
 public:
  long long maxSubarraySum(std::vector<int>& nums, int k) {
    long ans = LONG_MIN;
    long prefix = 0;
    // minPrefix[i % k] := the minimum prefix sum of the first i numbers
    vector<long> minPrefix(k, LONG_MAX / 2);
    minPrefix[k - 1] = 0;

    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i];
      ans = max(ans, prefix - minPrefix[i % k]);
      minPrefix[i % k] = min(minPrefix[i % k], prefix);
    }

    return ans;
  }
};
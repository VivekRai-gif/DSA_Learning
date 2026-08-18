class Solution {
public:

    // dp[l][r] = maximum score Alice can get
    // from subarray l to r
    int dp[501][501];

    int solve(int l, int r, vector<int>& prefix) {

        // Only one stone
        if (l == r) {
            return 0;
        }

        // Already calculated
        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        int ans = 0;

        // Try every possible split
        for (int k = l; k < r; k++) {

            // [l ... k] | [k+1 ... r]

            int leftSum = prefix[k + 1] - prefix[l];

            int rightSum = prefix[r + 1] - prefix[k + 1];


            // Left side is smaller
            if (leftSum < rightSum) {

                // Alice gets leftSum
                // Continue game on left side
                ans = max(ans,
                          leftSum + solve(l, k, prefix));
            }


            // Right side is smaller
            else if (rightSum < leftSum) {

                // Alice gets rightSum
                // Continue game on right side
                ans = max(ans,
                          rightSum + solve(k + 1, r, prefix));
            }


            // Both sides are equal
            else {

                // Alice can choose either side
                ans = max(ans,
                          leftSum +
                          max(
                              solve(l, k, prefix),
                              solve(k + 1, r, prefix)
                          ));
            }
        }

        return dp[l][r] = ans;
    }


    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        // Prefix sum
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        // Initialize DP
        memset(dp, -1, sizeof(dp));

        return solve(0, n - 1, prefix);
    }
};
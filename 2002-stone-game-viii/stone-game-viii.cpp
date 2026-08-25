class Solution {
public:
    int n;
    int t[100000];
    bool visited[100000];

    int solve(int i, vector<int>& prefixsum)
    {
        if (i == n - 1) {
            return prefixsum[n - 1];
        }

        if (visited[i]) {
            return t[i];
        }

        visited[i] = true;

        int take = prefixsum[i] - solve(i + 1, prefixsum);
        int skip = solve(i + 1, prefixsum);

        return t[i] = max(take, skip);
    }

    int stoneGameVIII(vector<int>& stones)
    {
        n = stones.size();

        memset(visited, false, sizeof(visited));

        vector<int> prefixsum(n);

        prefixsum[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefixsum[i] = prefixsum[i - 1] + stones[i];
        }

        return solve(1, prefixsum);
    }
};
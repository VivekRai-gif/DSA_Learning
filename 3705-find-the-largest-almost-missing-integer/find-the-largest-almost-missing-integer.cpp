class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();

        // number -> kitni subarrays mein appear hua
        unordered_map<int, int> count;

        // Har subarray of size k
        for (int i = 0; i <= n - k; i++) {

            // Current subarray mein kaunse numbers already aa chuke hain
            unordered_set<int> seen;

            for (int j = 0; j < k; j++) {

                int x = nums[i + j];

                // Current subarray mein pehli baar mila
                if (seen.find(x) == seen.end()) {
                    count[x]++;
                    seen.insert(x);
                }
            }
        }

        int ans = -1;

        // Exactly one subarray mein aaya
        for (auto it : count) {

            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};
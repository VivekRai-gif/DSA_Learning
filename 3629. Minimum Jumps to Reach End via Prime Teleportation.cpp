class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int mx = *max_element(nums.begin(), nums.end());

        // Smallest Prime Factor (SPF) sieve
        vector<int> spf(mx + 1);
        for (int i = 0; i <= mx; i++) spf[i] = i;

        for (long long i = 2; i * i <= mx; i++) {
            if (spf[i] == i) {
                for (long long j = i * i; j <= mx; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        // prime -> indices divisible by prime
        unordered_map<int, vector<int>> divisible;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            unordered_set<int> used;

            while (x > 1) {
                int p = spf[x];
                used.insert(p);

                while (x % p == 0)
                    x /= p;
            }

            for (int p : used)
                divisible[p].push_back(i);
        }

        vector<int> dist(n, -1);
        queue<int> q;

        q.push(0);
        dist[0] = 0;

        unordered_set<int> usedPrimeTeleport;

        auto isPrime = [&](int x) {
            if (x < 2) return false;
            return spf[x] == x;
        };

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int d = dist[i];

            if (i == n - 1) return d;

            // adjacent left
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = d + 1;
                q.push(i - 1);
            }

            // adjacent right
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = d + 1;
                q.push(i + 1);
            }

            // prime teleport
            int val = nums[i];

            if (isPrime(val) && !usedPrimeTeleport.count(val)) {
                usedPrimeTeleport.insert(val);

                for (int nxt : divisible[val]) {
                    if (dist[nxt] == -1) {
                        dist[nxt] = d + 1;
                        q.push(nxt);
                    }
                }
            }
        }

        return -1;
    }
};

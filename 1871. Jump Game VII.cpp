class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        queue<int> q;
        q.push(0);

        int far = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int start = max(i + minJump, far);
            int end = min(i + maxJump, n - 1);

            for (int j = start; j <= end; j++) {
                if (s[j] == '0') {
                    if (j == n - 1)
                        return true;

                    q.push(j);
                }
            }

            far = i + maxJump + 1;
        }

        return n == 1;
    }
};

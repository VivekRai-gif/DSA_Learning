class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n, INF);
        int answer = INF;

        int left = 0;
        int sum = 0;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            if (sum == target) {
                int length = right - left + 1;

                // Combine with a subarray completely before 'left'
                if (left > 0 && best[left - 1] != INF) {
                    answer = min(answer, best[left - 1] + length);
                }

                // Store the shortest valid subarray seen so far
                if (right == 0) {
                    best[right] = length;
                } else {
                    best[right] = min(best[right - 1], length);
                }
            } else if (right > 0) {
                best[right] = best[right - 1];
            }
        }

        return answer == INF ? -1 : answer;
    }
};
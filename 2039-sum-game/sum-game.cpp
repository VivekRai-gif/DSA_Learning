class Solution {
public:
    bool sumGame(string num) {

        int n = num.length();
        int mid = n / 2;

        int left_sum = 0;
        int right_sum = 0;

        int left_q = 0;
        int right_q = 0;

        // First half
        for (int i = 0; i < mid; i++) {
            if (num[i] == '?') {
                left_q++;
            }
            else {
                left_sum += num[i] - '0';
            }
        }

        // Second half
        for (int i = mid; i < n; i++) {
            if (num[i] == '?') {
                right_q++;
            }
            else {
                right_sum += num[i] - '0';
            }
        }

        // Odd number of '?' -> Alice gets the last move
        if ((left_q + right_q) % 2 == 1) {
            return true;
        }

        int sum_diff = left_sum - right_sum;
        int q_diff = right_q - left_q;

        // Bob can make sums equal only in this exact case
        if (sum_diff == 9 * q_diff / 2) {
            return false;
        }

        return true;
    }
};
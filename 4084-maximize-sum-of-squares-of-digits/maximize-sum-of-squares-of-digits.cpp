class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9LL * num) return "";

        string ans;
        ans.reserve(num);

        while (num > 0 && sum >= 9) {
            ans += '9';
            sum -= 9;
            num--;
        }

        if (num > 0) {
            ans += char('0' + sum);
            sum = 0;
            num--;
        }

        ans += string(num, '0');
        return ans;
    }
};
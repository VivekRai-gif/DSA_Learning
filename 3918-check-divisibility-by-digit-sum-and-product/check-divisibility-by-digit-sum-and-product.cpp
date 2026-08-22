class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
      int sum = 0;
      int product = 1;
    while (n > 0) {
        int digit = n % 10;
        sum += digit;
        product *= digit;
        n = n / 10;
    }
    return (temp% (sum + product)==0);
    }
};
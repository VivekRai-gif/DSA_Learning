class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
      int sum = 0;
      int product = 1;
    while (n > 0) {
        int digit = n % 10;
        cout << digit << " ";
        sum += digit;
        product *= digit;
        n = n / 10;
    }
    int final = sum + product;
    return (temp%final==0);
    }
};
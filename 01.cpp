//setup demo question
#include <iostream>
using namespace std;

int main() {
    int num1, num2, sum;

    // Input
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    // Process
    sum = num1 + num2;

    // Output
    cout << "The sum of " << num1 << " and " << num2 << " is " << sum << endl;

    return 0;
}
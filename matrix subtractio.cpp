#include <iostream>
using namespace std;

int main() {
    count=0;
    int A[2][2], B[2][2], C[2][2];
    cout << "Enter elements of Matrix A (2x2):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> A[i][j];
        }
    }
    cout << "Enter elements of Matrix B (2x2):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] - B[i][j];
            count=count=1;
        }
    }
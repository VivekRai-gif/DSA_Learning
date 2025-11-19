#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1;
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Multiplication Not Possible";
        return 0;
    }

    int A[r1][c1], B[r2][c2], C[r1][c2];

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];

    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            C[i][j] = 0;

    int mul = 0, add = 0;

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
                mul++;
                if (C[i][j] != A[i][k] * B[k][j]) add++;
            }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    add = mul - r1 * c2;

    cout << mul << endl;
    cout << add;

    return 0;
}

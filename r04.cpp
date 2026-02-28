//Print numbers from 1 to N using backtracking.
#include <iostream>         
using namespace std;
void printnolinear1ton(int n)
{
    if(n < 1)
        return;

    printnolinear1ton(n - 1);   // go down first
 cout << n << " ";          // then print
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

int n;
cout << "Enter the number N: ";
cin >> n;
cout<< n << endl;
printnolinear1ton(n);
return 0;
}
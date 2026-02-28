// Print numbers linearly from 1 to N

#include <iostream>
using namespace std;    

void printNormal(int i, int n)
{
    if(i > n)   // base case
        return;

    cout << i << " ";      // print first
    printNormal(i + 1, n); // then recursive call
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
printNormal(1, n);
return 0;
}
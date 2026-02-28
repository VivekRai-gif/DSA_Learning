// Print numbers linearly from N to 1.

#include <iostream>
using namespace std;    
void printnolinear1ton(int n)
{
    if(n < 1)
        return;
    cout << n << " ";          // print first
    printnolinear1ton(n - 1);  
   
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
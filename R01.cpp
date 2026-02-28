// Print your name n times
#include <iostream>
using namespace std;

void printnumber(int n);   // 🔹 Function declaration

int main()
{ 
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

    int n;
    cout << "Enter the number of times to print your name: ";
    cin >> n;
    cout<< n << endl;
    printnumber(n);
    return 0;
}

void printnumber(int n)
{
    if(n < 1)
        return;

    cout << "Name = VVK" << endl;
    printnumber(n - 1);
}
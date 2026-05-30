// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
    int ans = INT_MAX;
    for (int num : nums) {
        int sum = 0;
            while (num > 0) 
            {   sum += num % 10;
                num /= 10;
                
            }
                ans = min(ans, sum);
            }
        return ans;
        }
    };
    int main()
    {
     int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    cout << "Answer = " << obj.minElement(nums);

    return 0;
}

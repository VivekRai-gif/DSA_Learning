// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // sort(nums.begin(),nums.end());
        // return nums;
        // need not to change the order
        vector<int> ans;
        //small then pivot ko push 
        for(int i=0;i<nums.size();i++)
        {
           if(nums[i] < pivot)
            {
                ans.push_back(nums[i]);
            }
        }
        //equal wala case
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == pivot)
            {
                ans.push_back(nums[i]);
            }
        }
        //larger then pivot ko push
         for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>pivot)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
 int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int pivot;
    cout << "Enter pivot: ";
    cin >> pivot;
//objrct created
    Solution obj;
    vector<int> result = obj.pivotArray(nums, pivot);

    cout << "Result: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

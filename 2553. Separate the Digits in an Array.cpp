class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> output;

        for (int num : nums) {

            string s = to_string(num);

            for (char c : s) {
                output.push_back(c - '0');
            }
        }

        return output;
    }
};

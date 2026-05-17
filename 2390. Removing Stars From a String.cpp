class Solution {
public:
    string removeStars(string s) {
        string ans;

        for(char ch : s) {
            if(ch == '*') {
               if(!ans.empty())
                    ans.pop_back();
            }
            else {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};

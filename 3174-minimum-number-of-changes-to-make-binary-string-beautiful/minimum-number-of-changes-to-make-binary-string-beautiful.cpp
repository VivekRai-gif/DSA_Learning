class Solution {
public:
    int minChanges(string s) {
    int changes = 0;
      for (int i = 0; i < s.size(); i += 2) {
          changes += (s[i] != s[i + 1]);
      }
       return changes;
    }
};
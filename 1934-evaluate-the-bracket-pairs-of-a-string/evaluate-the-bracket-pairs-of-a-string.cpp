class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto &kv : knowledge) {
            mp[kv[0]] = kv[1];
        }

        string res;
        string key;
        bool inBracket = false;

        for (char c : s) {
            if (c == '(') {
                inBracket = true;
                key.clear();
            } else if (c == ')') {
                inBracket = false;
                auto it = mp.find(key);
                if (it != mp.end()) {
                    res += it->second;
                } else {
                    res += '?';
                }
                key.clear();
            } else {
                if (inBracket) {
                    key += c;
                } else {
                    res += c;
                }
            }
        }

        return res;
    }
};
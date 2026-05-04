class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        // count frequency
        for (int num : arr) {
            freq[num]++;
        }

        // store frequencies in set
        unordered_set<int> s;
        for (auto &p : freq) {
            s.insert(p.second);
        }

        // if sizes match → all frequencies unique
        return freq.size() == s.size();
    }
};

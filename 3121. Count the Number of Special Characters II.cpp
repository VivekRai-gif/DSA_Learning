class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, -1);

        for (int i = 0; i < word.size(); i++) {
            
            char ch = word[i];

            if (ch >= 'a' && ch <= 'z') {
                lastLower[ch - 'a'] = i;
            }
            else if (ch >= 'A' && ch <= 'Z') {

                // first uppercase only
                if (firstUpper[ch - 'A'] == -1) {
                    firstUpper[ch - 'A'] = i;
                }
            }
        }

        int count = 0;

        for (int i = 0; i < 26; i++) {

            // small exists AND capital exists
            // and small comes first
            if (lastLower[i] != -1 &&
                firstUpper[i] != -1 &&
                lastLower[i] < firstUpper[i]) {

                count++;
            }
        }

        return count;
    }
};

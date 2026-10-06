class Solution {
public:
    int minAddToMakeValid(string s) {
    int open_needed = 0; // unmatched '('
    int add = 0;         // insertions needed

    for (char c : s) {
        if (c == '(') {
            open_needed++;
        } else { // c == ')'
            if (open_needed > 0) {
                // match with a previous '('
                open_needed--;
            } else {
                // no '(' to match this ')', so we must insert one '('
                add++;
            }
        }
    }

    // remaining open_needed '(' each need a ')'
    add += open_needed;
    return add;
}
};
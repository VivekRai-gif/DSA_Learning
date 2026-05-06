class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // Step 1: transpose
        vector<vector<char>> ans(n, vector<char>(m));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                ans[j][i] = boxGrid[i][j];
            }
        }

        // Step 2: reverse every row
        for(int i = 0; i < n; i++) {

            reverse(ans[i].begin(), ans[i].end());
        }

        // Step 3: apply gravity
        for(int col = 0; col < m; col++) {

            int empty = n - 1;

            for(int row = n - 1; row >= 0; row--) {

                if(ans[row][col] == '*') {
                    empty = row - 1;
                }

                else if(ans[row][col] == '#') {

                    swap(ans[row][col], ans[empty][col]);
                    empty--;
                }
            }
        }

        return ans;
    }
};

// Link : https://takeuforward.org/plus/dsa/problems/set-matrix-zeroes
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int m = matrix.size();
        int n = matrix[0].size();

        bool firstRow = false, firstCol = false;

        // Check if first row has any zero
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRow = true;
                break;
            }
        }

        // Check if first column has any zero
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }

        // Mark rows and columns
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set elements to zero based on markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero first row if needed
        if (firstRow) {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }

        // Zero first column if needed
        if (firstCol) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transwerse and then reverse all row
        for (int i=0;i<matrix.size();i++)
             {for (int j=i+1;j<matrix.size();j++)
                 {
            swap(matrix[i][j],matrix[j][i]);
           
                    }
    }
     for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

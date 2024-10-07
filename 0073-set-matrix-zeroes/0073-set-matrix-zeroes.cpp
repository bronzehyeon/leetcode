class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();

        unordered_set<int> row;
        unordered_set<int> col;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for (int r : row) {
            for (int j = 0; j < M; j++) {
                matrix[r][j] = 0;
            }
        }

        for (int c : col) {
            for (int i = 0; i < N; i++) {
                matrix[i][c] = 0;
            }
        }
    }
};
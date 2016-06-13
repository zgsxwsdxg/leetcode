class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int R = matrix.size();
            if(R <= 0) return ;
            int C = matrix[0].size();
            if(C <= 0) return ;
            vector<bool> rows(R, false);
            vector<bool> cols(C, false);
            for(int i = 0; i < R; ++i){
                for(int j = 0; j < C; ++j){
                    rows[i] = rows[i] | (matrix[i][j] == 0);
                    cols[j] = cols[j] | (matrix[i][j] == 0);
                }
            }
            for(int i = 0; i < R; ++i){
                if(rows[i]){
                    for(int j = 0; j < C; ++j){
                        matrix[i][j] = 0;
                    }
                }
            }
            for(int j = 0; j < C; ++j){
                if(cols[j]){
                    for(int i = 0; i < R; ++i){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
};
class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int R = matrix.size();
            if(R <= 0) return ;
            int C = matrix[0].size();
            if(C <= 0) return ;
            bool firstRow = false;
            bool firstCol = false;
            for(int i = 0; i < C; ++i){
              firstRow |= matrix[0][i] == 0;
            }
            for(int i = 0; i < R; ++i){
              firstCol |= matrix[i][0] == 0;
            }
            for(int i = 1; i < R; ++i){
                for(int j = 1; j < C; ++j){
                    if(matrix[i][j] == 0){
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
            for(int i = 1; i < R; ++i){
                if(matrix[i][0] == 0){
                    for(int j = 1; j < C; ++j){
                        matrix[i][j] = 0;
                    }
                }
            }
            for(int j = 1; j < C; ++j){
                if(matrix[0][j] == 0){
                    for(int i = 1; i < R; ++i){
                        matrix[i][j] = 0;
                    }
                }
            }
            if(firstRow){
                for(int i = 0; i < C ; ++i){
                    matrix[0][i] = 0;
                }
            }
            if(firstCol){
                for(int i = 0; i < R; ++i){
                    matrix[i][0] = 0;
                }
            }
        }
};|

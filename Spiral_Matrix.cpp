class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> res;
            int top = 0;
            int down = matrix.size() - 1;
            int left = 0;
            if (matrix.size() <= 0) return res;
            int right = matrix[0].size() - 1;
            for (;;){
                if (left <= right){
                    for (int i = left; i <= right; ++i){
                        res.push_back(matrix[top][i]);
                    }
                    ++top;
                }
                else break;
                if (top <= down){
                    for (int i = top; i <= down; ++i){
                        res.push_back(matrix[i][right]);
                    }
                    --right;
                }
                else break;
                if (left <= right){
                    for (int i = right; i >= left; --i){
                        res.push_back(matrix[down][i]);
                    }
                    --down;
                }
                else break;
                if (top <= down){
                    for (int i = down; i >= top; --i){
                        res.push_back(matrix[i][left]);
                    }
                    ++left;
                }
                else break;
            }
            return res;
        }
};

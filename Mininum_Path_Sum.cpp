class Solution {
	public:
		int minPathSum(vector<vector<int>>& grid) {
			if(grid.size() <= 0) return 0;
			int N = grid.size();
			int M = grid[0].size();
			vector<int> record(M);
			record[0] = grid[0][0];
			for(int i = 1; i < M; ++i){
				record[i] = grid[0][i] + record[i - 1];
			}
			for(int i = 1; i < N; ++i){
				record[0] += grid[i][0];
				for(int j = 1; j < M; ++j){
					record[j] = std::min(record[j - 1] , record[j] ) + grid[i][j];
				}
			}
			return record[M - 1];
		}
};

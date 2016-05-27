class Solution {
	public:
		int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
			if(obstacleGrid.size() <= 0) return 0;
			size_t cols = obstacleGrid[0].size();
			if(cols <= 0) return 0;
			vector<int> records(cols,0);
			records[0] = 1;
			for(size_t i = 0; i < obstacleGrid.size(); ++i){
				records[0] = records[0] * (1 - obstacleGrid[i][0]);
				for(int j = 1; j < cols; ++j){
					records[j] = (records[j - 1] + records[j]) *(1 - obstacleGrid[i][j]);
				}
			}
			return records[cols -1];
		}
};

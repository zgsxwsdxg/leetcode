class Solution {
	public:
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			int rows = matrix.size();
			int cols = matrix[0].size();
			int left = 0;
			int right = rows * cols  - 1;
			while(left <= right){
				int mid = left + ((right - left) >> 1);
				int t = matrix[mid/cols][mid%cols];
				if( t == target){
					return true;
				}
				else if(t > target){
					right = mid - 1;
				}
				else{
					left = mid + 1;
				}
			}
			return false;
		}
};

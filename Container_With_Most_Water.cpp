class Solution {
	public:
		int maxArea(vector<int>& height) {
			int left = 0;
			int right = (int) height.size() -1;
			int maxarea = 0;
			while(left < right){
				maxarea = std::max(maxarea, std::min(height[left], height[right]) *(right - left));
				if(height[left] > height[right]) --right;
				else ++left;
			}
			return maxarea;
		}
};

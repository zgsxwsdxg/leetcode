class Solution {
	public:
		int trap(vector<int>& height) {
			int index = 0;
			for(size_t i = 0; i < height.size(); ++i){
				if(height[i] > height[index]){
					index = i;
				}
			}
			int curheight = 0;
			int sum = 0;
			for(int i = 0; i < index; ++i){
				curheight = max(curheight, height[i]);
				sum += curheight - height[i];
			}
			curheight = 0;
			for(int i = height.size() - 1; i > index; --i){
				curheight = max(curheight, height[i]);
				sum += curheight - height[i];
			}
			return sum;
		}
};

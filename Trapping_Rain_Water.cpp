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


class Solution {
	public:
		int trap(vector<int>& height) {
			int res = 0;
			int left = 0, right = height.size() - 1;
			int leftheight = 0;
			int rightheight = 0;
			while(left < right){
				if(height[left] <= height[right]){
					leftheight = max(leftheight, height[left]);
					res += leftheight - height[left];
					++left;
				}
				else{
					rightheight = max(rightheight, height[right]);
					res += rightheight - height[right];
					--right;
				}
			}
			return res;
		}
};

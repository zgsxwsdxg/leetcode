class Solution {
	public:
		vector<vector<int>> subsets(vector<int>& nums) {
			sort(nums.begin(),nums.end());
			this->n=nums.size();
            /*
			for(int i=0;i<=nums.size();i++){
				this->k=i;
				com(0,0,nums);
			}
			*/
			com(0,nums);
			return vvi;
		}
	private:
		//版本一：个数优先,遍历整个长度。
		void com(int j,int t,vector<int>& nums){
			if(j==k){
				vvi.push_back(vi);
			}
			else{
				for(int i=t;i<n;i++){
					vi.push_back(nums[i]);
					com(j+1,i+1,nums);
					vi.pop_back();
				}
			}
		}
		//版本二：深度优先
		void com(int pos,vector<int>& nums){
			vvi.push_back(vi);
			if(pos>=n) return ;
			for(int i=pos;i<n;i++){
				vi.push_back(nums[i]);
				com(i+1,nums);
				vi.pop_back();
			}
		}
	private:
		vector<vector<int>> vvi;
		vector<int> vi;
		int k;
		int n;
};

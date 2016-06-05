class Solution {
	public:
		int hammingWeight(uint32_t n) {
			int cnt = 0;
			while(n){
				++cnt;
				n = n&(n-1);
			}
			return cnt;
		}
};

class Solution {
	public:
		int hammingWeight(uint32_t n) {
			int res = 0;
			for(int i = 0; i < 32; ++i){
				res += static_cast<int>(((1 << i) & n) != 0);
			}
			return res;
		}
};

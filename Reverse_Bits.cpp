class Solution {
	public:
		uint32_t reverseBits(uint32_t n) {
			int res = 0;
			for(int i = 0; i < 32; ++i){
				res = res * 2 + static_cast<int>(((1 << i)& n) != 0);
			}
			return res;
		}
};

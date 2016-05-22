// 版本一 ，记录当前字母是否出现过？
class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int pos[256] ={0};
			int left = 0;
			int right = 0;
			int len = 0;
			for(size_t i = 0; i < s.size(); ++i){
				if(pos[s[i]] == 1){
					while(s[left] != s[i]){
						pos[s[left]] = 0;
						++left;
					}
					pos[s[left]] = 0;
					++left;
				}
				pos[s[i]] = 1;
				right = i;
				len = std::max(len, right - left + 1);
			}
			return len;
		}
};

//版本二，记录跳转位置
class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int pos[256] = {0};
			int left = 0;
			int len = 0;
			for(size_t i = 0; i < s.size(); ++i){
				if(pos[s[i]] > left){
					left = pos[s[i]];
				}
				pos[s[i]] = i + 1;
				len = std::max(len, static_cast<int>(i) - left + 1);
			}
			return len;
		}
};

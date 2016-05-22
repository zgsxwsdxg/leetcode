class Solution {
	public:
		string longestCommonPrefix(vector<string>& strs) {
			if (strs.size() == 0) return "";
			return longestCommonPrefix(strs, 0, strs.size() - 1);
		}
	private:
		string longestCommonPrefix(vector<string>& strs,size_t begin,size_t end) {
			if (begin >= end) return strs[begin];
			size_t mid = ((begin + end) >> 1);
			string p1 = longestCommonPrefix(strs, begin, mid);
			string p2 = longestCommonPrefix(strs, mid + 1, end);
			return longestCommonPrefix(p1, p2);
		}
		string longestCommonPrefix(string& str1, string str2) {
			size_t len = std::min(str1.size(), str2.size());
			size_t i = 0;
			for (; i < len; ++i){
				if (str1[i] != str2[i]) break;
			}
			return str1.substr(0, i);
		}
};

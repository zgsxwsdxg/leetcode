class Solution {
    public:
        string longestPalindrome(string s) {
            string res;
            for(size_t i = 0; i < s.size(); ++i){
                int left = i - 1;
                while(i + 1 < s.size() && s[i + 1] == s[i]) ++i;
                int right = i + 1;
                while(left >= 0 && right < s.size() && s[left] == s[right]){
                    --left;
                    ++right;
                }
                if(right - left - 1 > res.size()){
                    res = s.substr(left + 1,right - left - 1);
                }
            }
            return res;
        }
};

class Solution {
    public:
        string longestPalindrome(string s) {
            string res;
            int pos = 0, len = 0;
            for(size_t i = 0; i < s.size(); ++i){
                int left = i - 1;
                while(i + 1 < s.size() && s[i + 1] == s[i]) ++i;
                int right = i + 1;
                while(left >= 0 && right < s.size() && s[left] == s[right]){
                    --left;
                    ++right;
                }
                if(right - left - 1 > len){
                    len = right - left -1;
                    pos = left + 1;
                }
            }
            res = s.substr(pos, len);
            return res;
        }
};

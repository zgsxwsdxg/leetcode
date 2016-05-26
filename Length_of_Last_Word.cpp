class Solution {
    public:
        int lengthOfLastWord(string s) {
            int pos = s.size() - 1;
            for(; pos >= 0 && s[pos] == ' '; --pos);
            int len = 0;
            for(; pos >= 0 && s[pos] != ' '; --pos){
                ++len;
            }
            return len;
        }
};

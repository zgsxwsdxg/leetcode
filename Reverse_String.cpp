class Solution {
    public:
        string reverseString(string s) {
            int len = s.size();
            for(int i = 0; i < len/2; ++i){
                std::swap(s[i], s[len - 1 - i]);
            }
            return s;
        }
};

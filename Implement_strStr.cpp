class Solution {
    public:
        int strStr(string haystack, string needle) {
            if(needle.size() == 0) return 0;
            int len = haystack.size() - needle.size();
            for(int i = 0; i <= len; ++i){
                int p = i;
                int j = 0;
                while(p < haystack.size() && j < needle.size() && haystack[p] == needle[j]){
                    ++p;
                    ++j;
                }
                if(j == needle.size()){
                    return i;
                }
            }
            return -1;
        }
};

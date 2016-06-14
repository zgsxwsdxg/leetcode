class Solution {
    public:
        string convert(string s, int numRows) {
            if(numRows <= 1) return s;
            vector<string> strs(numRows,"");
            int d = -1;int step = 1;
            for(auto ch : s){
                if(d >= numRows -1){
                    step = -1;
                }
                if(d <= 0){
                    step = 1;
                }
                strs[d += step] +=ch;
            }
            string res;
            for(auto& str : strs){
                res += str; // append push_back
            }
            return res;
        }
};

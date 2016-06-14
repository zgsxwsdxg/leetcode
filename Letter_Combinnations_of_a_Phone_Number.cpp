class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            string d2str[] = {"","", "abc", "def", "ghi", "jkl", "mno","pqrs","tuv","wxyz"};
            vector<string> res;
            if(digits.size() <= 0) return res;
            res.push_back("");
            for(auto d : digits){
                string str1 = d2str[d - '0'];
                if(str1.size() == 0) continue;
                vector<string> tmp;
                res.swap(tmp);
                res.clear();
                for(auto oldstr : tmp){
                    for(auto ch : str1){
                        string newstr = oldstr + ch;
                        res.emplace_back(newstr);
                    }
                }
            }
            return res;
        }
};

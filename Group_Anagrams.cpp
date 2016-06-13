class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            map<string,vector<string>> resm;
            for(auto& str : strs){
                string key = str;
                sort(key.begin(),key.end());
                if(resm.find(key) != resm.end()){
                    resm[key].push_back(str);
                }
                else{
                    vector<string> strv;
                    strv.push_back(str);
                    resm[key]=(strv);
                }
            }
            vector<vector<string>> res;
            for(map<string,vector<string>>::iterator it = resm.begin(); it != resm.end(); ++it){
                res.emplace_back(it->second);
            }
            return res;
        }
};
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            map<string,int> resm;
            vector<vector<string>> res;
            for(auto& str : strs){
                string key = str;
                sort(key.begin(),key.end());
                if(resm.find(key) != resm.end()){
                    res[resm[key]].push_back(str);
                }
                else{
                    resm[key] = res.size();
                    vector<string> t;
                    t.push_back(str);
                    res.emplace_back(t);
                }
            }
            return res;
        }
};

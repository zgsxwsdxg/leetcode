class Solution {
    public:
        int maxProduct(vector<string>& words) {
            size_t len = 0;
            vector<int> records(words.size());
            for(size_t i = 0; i < words.size(); ++i){
                int k = 0;
                for(auto ch : words[i]){
                    k |= (1 << ch - 'a');
                }
                records[i] = k;
            }
            for(size_t i = 0; i < words.size(); ++i){
                for(size_t j = i+1; j < words.size(); ++j){
                    if((records[i] & records[j]) == 0){
                        len = std::max(len, words[i].size() * words[j].size());
                    }
                }
            }
            return len;
        }
};

class Solution {
    public:
        int maxProduct(vector<string>& words) {
            size_t len = 0;
            vector<int> records(words.size());
            for(size_t i = 0; i < words.size(); ++i){
                int k = 0;
                for(auto ch : words[i]){
                    k |= (1 << ch - 'a');
                }
                records[i] = k;
                for(size_t j = 0; j < i; ++j){
                    if((records[i]&records[j]) == 0){
                        len = std::max(len, words[i].size()* words[j].size());
                    }
                }
            }
            return len;
        }
};

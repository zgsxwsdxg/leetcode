class solution{
    public:
        void add(int x){
            for (auto n : arr){
                su.insert(n + x);
            }
            arr.push_back(x);
        }
        bool find(int target){
            return su.find(target) != su.end();
        }
    private:
        vector<int> arr;
        set<int> su;
};

class solution2{
    public:
        void add(int x){
            ++hash[x];
        }
        bool find(int target){
            for (auto m : hash){
                int v = target - m.first;
                if (v == m.first && m.second > 1 && hash.find(v) != hash.end()){
                    return true;
                }
            }
            return false;
        }
    private:
        unordered_map<int, int> hash;
};

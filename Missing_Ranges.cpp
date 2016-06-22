class Sulotion{
    public:
        vector<string> missingRanges(vector<int>& nums){
            int pre = -1;
            vector<string> res;
            nums.push_back(100); // 哨兵;
            for (auto n : nums){
                if (n - pre != 1){
                    if (pre + 1 == n - 1){
                        res.emplace_back(to_string(pre + 1));
                    }
                    else{
                        res.emplace_back(to_string(pre + 1) + "->" + to_string(n - 1));
                    }
                }
                pre = n;
            }
            nums.pop_back();//delete 哨兵
            //if (pre < 99){
            //  if (pre == 98){
            //      res.emplace_back(to_string(99));
            //  }
            //  else{
            //      res.emplace_back(to_string(pre + 1) + "->" + to_string(99));
            //  }
            //}
            return res;
        }
};

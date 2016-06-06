class Solution {
    public:
        int hIndex(vector<int>& citations) {
            std::sort(citations.begin(),citations.end());
            int h = 0;
            for(int i = citations.size() - 1, j = 1; i >= 0; --i,++j){
                h = std::max(h,std::min(j, citations[i]));
            }
            return h;
        }
};

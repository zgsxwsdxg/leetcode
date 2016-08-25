class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            std::unordered_map<int, int> umap;
            for (auto n : nums){
                ++umap[n];
            }
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;// 小顶堆
            for (auto & m : umap){
                if (pq.size() >= k){
                    if (pq.top().first < m.second){
                        pq.pop();
                        pq.push(make_pair(m.second, m.first));
                    }
                }
                else{
                    pq.push(make_pair(m.second, m.first));
                }
            }
            vector<int> res(k);
            for (int i = k -1; i >= 0; --i){
                res[i] = pq.top().second;
                pq.pop();
            }
            return res;
        }
};

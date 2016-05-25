/**
 ** Definition for an interval.
 ** struct Interval {
 **     int start;
 **     int end;
 **     Interval() : start(0), end(0) {}
 **     Interval(int s, int e) : start(s), end(e) {}
 ** };
 **/
class Solution {
    public:
        vector<Interval> merge(vector<Interval>& intervals) {
            vector<Interval> res;
            if(intervals.size() < 1) return res;
            std::sort(intervals.begin(),intervals.end(),[](Interval& it1, Interval& it2){
                    return it1.start == it2.start ? it1.end < it2.end : it1.start < it2.start;
                    });
            Interval it(intervals[0].start,intervals[0].end);
            for(size_t i = 1; i < intervals.size(); ++i){
                if(it.end >= intervals[i].start){
                    it.end = std::max(it.end, intervals[i].end);
                }
                else{
                    res.emplace_back(it);
                    it.start = intervals[i].start;
                    it.end = intervals[i].end;
                }
            }
            res.emplace_back(it);
            return res;
        }
};

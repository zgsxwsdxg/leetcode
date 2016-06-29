/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 **/
class Solution {
    public:
        int maxPoints(vector<Point>& points) {
            int cnt = 0;
            for(size_t i = 0; i < points.size(); ++i){
                map<double, int> theta;
                int same = 0;
                int tmpcnt = 0;
                for(size_t j = i + 1; j < points.size(); ++j){
                    if(points[i].x == points[j].x && points[i].y == points[j].y){
                        ++same;
                    }
                    else if(points[i].x == points[j].x){
                        ++theta[INT_MAX];
                        tmpcnt = std::max(tmpcnt, theta[INT_MAX]);
                    }
                    else{
                        double th= 1.0*(points[i].y - points[j].y) / (points[i].x - points[j].x);
                        ++theta[th];
                        tmpcnt = std::max(tmpcnt, theta[th]);
                    }
                }
                cnt = std::max(cnt, tmpcnt + same + 1);
            }
            return cnt;
        }
};

class Solution {
    public:
        int maxPoints(vector<Point>& points) {
            if(points.size() <= 2) return points.size();
            int cnt = 0;
            for(size_t i = 0; i < points.size(); ++i){
                map<double, int> theta;
                int same = 0;
                int tmpcnt = 0;
                for(size_t j = i + 1; j < points.size(); ++j){
                    if(points[i].x == points[j].x && points[i].y == points[j].y){
                        ++same;
                    }
                    else if(points[i].x == points[j].x){
                        ++theta[INT_MAX];
                    }
                    else{
                        double th= 1.0*(points[i].y - points[j].y) / (points[i].x - points[j].x);
                        ++theta[th];
                    }
                }
                for(auto & th : theta){
                    tmpcnt= std::max(tmpcnt, th.second);
                }
                cnt = std::max(tmpcnt+ same + 1, cnt);
            }
            return cnt;
        }
};

class Solution {
    public:
        int maxPoints(vector<Point>& points) {
            if(points.size() <= 2) return points.size();
            int cnt = 0;
            for(size_t i = 0; i < points.size(); ++i){
                map<pair<int, int>, int> theta;
                int same = 0;
                int tmpcnt = 0;
                for(size_t j = i + 1; j < points.size(); ++j){
                    if(points[i].x == points[j].x && points[i].y == points[j].y){
                        ++same;
                    }
                    else if(points[i].x == points[j].x){
                        ++theta[make_pair(0,0)];
                    }
                    else{
                        int d_x = points[i].x - points[j].x;
                        int d_y = points[i].y - points[j].y;
                        int g = gcd(d_x, d_y);
                        ++theta[make_pair(d_x/ g, d_y/g)];
                    }
                }
                for(auto & th : theta){
                    tmpcnt= std::max(tmpcnt, th.second);
                }
                cnt = std::max(tmpcnt+ same + 1, cnt);
            }
            return cnt;
        }
        inline int gcd(int x, int y){
            while(y){
                int t = x % y;
                x = y;
                y = t;
            }
            return x;
        }
};

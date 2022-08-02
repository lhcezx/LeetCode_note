class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](const auto& a, const auto& b) {return a[1] < b[1];});           //  将所有区间结尾升序排列
        int prev = 0;
        int res = 1;                        //  统计同有多少个不重叠子区间
        for (int i = 0; i < points.size(); i++) {
            int start = points[i][0];
            int end = points[prev][1];
            if (start > end) {              //  判断条件为当后面的子区间开头大于前面的子区间的结尾时，代表找到了新的不重叠子区间
                prev = i;                   //  找到了第一个不重叠的子区间
                res++;
            }
        }
        return res;
    }
};
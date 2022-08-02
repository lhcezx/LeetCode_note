class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {return a[1] < b[1];});            //  将每个区间按照区间结尾排序
        int n = intervals.size();
        int prev = 0;
        int res = 1;
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[prev][1];
            if (start >= end) {
                prev = i;          //  当当前区间的开头比我们前面的区间的结尾要大时，说明两个区间没有重叠
                res++;             //  非重叠的子区间数量++
            }
        }
        return n - res;
    }
};
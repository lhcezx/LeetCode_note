//  将起点升序排列，前后两个数组只有两种情况: 重叠和不重叠. 我们首先将第一个数组放入res中. 若后面的数组起点比res.back()的终点大，则说明两个数组不重叠，将其放入res
//  若后面的数组起点比res.back()小，那么说明两个数组重叠，由于起点肯定res中的数组起点小，因此我们只需要判断两个数组的终点end哪个大，然后更新res中的back()数组的终点即可
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [&] (const auto& a, const auto& b) {return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];});
        res.push_back({intervals[0][0], intervals[0][1]});
        for (int i = 1; i < n; i++) {
            int end = res.back()[1];                        //  base line
            int next_start = intervals[i][0];            
            int next_end = intervals[i][1];
            if (next_start > end) {                         //  两个区间不重叠
                res.push_back({next_start, next_end});
            } else {                                        //  两个区间重叠
                res.back()[1] = max(end, next_end);
            }
        }
        return res;
    }
};
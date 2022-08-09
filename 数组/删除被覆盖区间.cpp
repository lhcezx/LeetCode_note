//  起点从小到大排列，终点从大到小排列，只需要判断区间的终点和前面区间的终点的关系即能判断是否能被覆盖
//  起点从小到大的排列让下面的区间的起点一定大于等于前面的区间的起点，只需要通过判断终点是否小于前一个区间即可判断是否覆盖.
//  终点从大到小排列是为了当起点相同时，判断能否将最长的区间覆盖，若不能，将base替换成该区间用于接下来的判断
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int counter = 0;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [&](const auto& a, const auto& b){return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];});
        int base_end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][1] <= base_end) {
                counter++;
            } else {
                base_end = intervals[i][1];
            }
        }
        return n - counter;
    }
};
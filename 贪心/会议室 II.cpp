class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> begin, end;
        for (auto interval: intervals) {
            begin.push_back(interval[0]);
            end.push_back(interval[1]);
        }
        sort(begin.begin(), begin.end());           //  将每个的区间的begin和end分别排序，相当于重组所有的会议时间，将所有的begin和end分别排序·可以理解为每个begin[i]对应的end[i]为一场重组会议
        sort(end.begin(), end.end());
        int res = 0;
        int count = 0;
        for (int i = 0, j = 0; i < n && j < n;) {
            if (begin[i] < end[j]) {                //  当begin[i] < end[j]的时候，即在[begin[i], end[j]]区间内存在多个begin，统计begin的个数就是需要的会议室的个数
                count++;
                i++;    
            } else {                                //  当begin[i] >= end[j]的时候，即begin[i]在[begin[i], end[j]]的end的后面，end[j]为结尾的会议结束，count--
                count--;        
                j++;
            }
            res = max(res, count);
        }
        return res;
    }
};
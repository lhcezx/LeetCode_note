class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [] (vector<int>& a, vector<int>& b) {      //  将intervals中每个数组按照起点排序
            return a[0] < b[0];
        });

        for (auto& interval: intervals) {
            if (res.empty() || interval[0] > res.back()[1]) res.push_back(interval);        //  当要加入的数组的启始大于数组中最后一个元素的末尾时，说明两个数组不会重合
            else res.back()[1] = max(res.back()[1], interval[1]);                           //  如果重叠，则判断末尾数组的终点和要加入数组的终点谁更远
        }
        return res;
    }
};
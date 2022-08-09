//  i,j 双指针分别指向两个区间，判断两个区间是否有交集, 若有交集则交集为[max(starts), min(ends)], 通过判断两个i, j区间的end决定哪个指针后移
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        for (int i = 0, j = 0; i < firstList.size() && j < secondList.size();) {
            int first_start = firstList[i][0];
            int first_end = firstList[i][1];
            int second_start = secondList[j][0];
            int second_end = secondList[j][1];
            if (first_start <= second_end && second_start <= first_end) {       //  两个区间必有交集
                int max_start = max(first_start, second_start);
                int min_end = min(first_end, second_end);
                res.push_back({max_start, min_end});
            }
            if (first_end < second_end) i++;
            else j++;
        }
        return res;
    }
};
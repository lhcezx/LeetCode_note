class Solution {
public:
    int getMinuits(string& t) {                 //  通过给定的时间计算出分钟数
        return (int(t[0] - '0') * 10 + int(t[1] - '0')) * 60 + int(t[3] - '0') * 10 + int(t[4] - '0');
    }

    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 1440) return 0;                 //  总共只能有1440种排列组合时间，若超过1440种，则必有两种是相同的，因此直接返回0
        sort(timePoints.begin(), timePoints.end());
        int res = INT_MAX;
        int t0 = getMinuits(timePoints[0]);                     //  记录下离0时刻最近的时间
        int prev = t0;
        for (int i = 1; i < timePoints.size(); i++){
            int cur = getMinuits(timePoints[i]);
            res = min(res, cur - prev);
            prev = cur;
        }
        res = min(res, t0 - prev + 1440);
        return res;
    }
};
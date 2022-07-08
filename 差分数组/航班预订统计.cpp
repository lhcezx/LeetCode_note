class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n);        //  差分数组初始化
        for (auto tmp: bookings) {
            int first = tmp[0] - 1, last = tmp[1] - 1, seats = tmp[2];   //  注意这里需要把读取的编号减一得到idx
            diff[first] += seats;
            if (last + 1 < n) diff[last + 1] -= seats;
        }
        for (int i = 1; i < n; i++) {
            diff[i] += diff[i-1];
        }
        return diff;
    }
};
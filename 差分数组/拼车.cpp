class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001);      //  题目中给出trips.length <= 1000
        for (auto tmp: trips) {
            int numP = tmp[0];       //  乘客的数量
            int from = tmp[1];       //  上车站
            int to = tmp[2];         //  下车站
            diff[from] += numP;      //  乘客在from站上车
            diff[to] -= numP;        //  乘客在to站下车
        }
        
        for (int i = 1; i < diff.size(); i++) {     //  恢复原数组，由于这里的原数组为0 所以直接用查分数组即可 否则res[i] = res[i-1] + diff[i]
            diff[i] += diff[i-1];
        }
        for (int c: diff) {
            if (c > capacity) return false;
            
        }
        return true;  
    }
};
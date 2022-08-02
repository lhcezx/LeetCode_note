class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int n = gas.size();
        //  计算每个加油站的净加油量: 当前加的油减去到下一个站要消耗的油, 如果净加油量最后为负，则必不可能环绕一周。若为正，则必然有一个方法能够让其环绕一周
        for (int i = 0; i < n; i++) {
            sum += gas[i] - cost[i];
        }
        if (sum < 0) return -1;  
        int tank = 0;                           //  油箱的油量
        int start = 0;
        for (int i = 0; i < n; i++) {
            tank += gas[i] - cost[i];
            //  若i位置邮箱净油量为负，则从start到i之间任意一个位置不可能作为起点，因为最终净油量都会为负，因此将start设置为从i+1开始
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return start == n ? 0 : start;
    }
};
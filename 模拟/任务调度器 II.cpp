class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long day = 0;
        unordered_map<int, long long> limites;                  //  记录某类任务前一次结束的时间点
        for (auto task: tasks) limites[task] = INT_MIN;                 
        for (int i = 0; i < tasks.size(); i++) {
            if (day - limites[tasks[i]] > space) {              //  如果间隔超过了space
                day++;
                limites[tasks[i]] = day;                        //  更新tasks[i]任务类型的前一次结束时间
            } else {                                            //  如果间隔小于space
                day = limites[tasks[i]] + space + 1;            //  直接将时间加到可以做tasks[i]那一天, 并修改tasks[i]的最近结束时间
                limites[tasks[i]] = day;
            }
        } 
        return day;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz = tasks.size();
        vector<int> cnt(26);
        for (char task: tasks) {
            cnt[task - 'A']++;
        }
        sort(cnt.begin(), cnt.end());                       //  将出现的次数从小到大排序
        //  cnt[25]代表出现次数最多的任务A的出现次数，n + 1代表一轮，也就是做完任务A以后的哪一天才能做下一个A. 出现次数最多的任务A要全部做完至少花费的天数为(cnt[25]-1)*(n+1) + 1, 这里的+1代表最后一次做任务A不需要再有间隔了
        int min_day = (cnt[25] - 1) * (n + 1) + 1;         
        for (int i = 0; i < cnt.size() - 1; i++) {
            if (cnt[i] == cnt[25]) min_day++;               //  如果某个任务出现的次数和出现次数最多的任务出现的次数相同，那么需要在最后增加一天
        }
        return max(min_day, sz);                            //  最后如果任务的总数比预定的位置还要多，那么最终完成时间是由任务的总数决定的
    }
};
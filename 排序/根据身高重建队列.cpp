class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        //  当身高不同的时候，将身高按照升序排列，先安排最矮的人。身高相同的时候，将前面的人数按照降序排列，先安排前面人数最多的那个人。因为同样身高的人前面依然排着和它相同身高的人，也就是身高相同情况下，如果前面的人更多，那实际上代表它更矮(即使是相同的身高)
        sort(people.begin(), people.end(), [&](const auto &a, const auto &b) {return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];});    
        vector<vector<int>> res(n);
        for (auto person: people) {
            int space = person[1];                      //  person[1]是前面应该有的人数
            for (int i = 0; i < n; i++) {
                if (space == 0 && res[i].empty()) {
                    res[i] = person;
                    break;
                }
                if (res[i].empty()) space--;            //  从头开始计数，计算当前总共有多少个空位，因为person的前面排有space个比他高的人。这里不计算已经安排的人，因为身高是从低到高安排，所以前面已经安排的人一定都比当前要安排的人矮，所以要预留space个位置给比它高的人

            }
        }
        return res;
    }
};
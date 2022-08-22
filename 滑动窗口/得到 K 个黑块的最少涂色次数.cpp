//  滑动窗口，统计长度为k的所有窗口里最多有多少个B
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = 0;
        int max_cnt;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'B') cnt++;
        }
        max_cnt = cnt;
        if (cnt == k) return 0;
        for (int i = k ; i < blocks.size(); i++) {
            if (blocks[i] == 'B') cnt++;
            if (blocks[i - k] == 'B') cnt--;
            max_cnt = max(max_cnt, cnt);
        }
        return k - max_cnt;
    }
};
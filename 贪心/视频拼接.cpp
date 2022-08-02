class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {  
        int n = clips.size();
        //  将clips中的每一个视频片段的起点按照升序排列，如果起点相同则将终点按照降序排列，为的是在同样的起点的情况下获得最长的视频片段
        sort(clips.begin(), clips.end(), [&](const auto& a, const auto& b) {return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];});
        int cur_end = 0, max_end = 0;
        int i = 0, res = 0;
        //  base case: cur_end初始化为0，第一段剪辑clips[0][0]为0时, 进入第一层while循环，第二层while循环会找到以0为起点，clips[i]最远的终点
        //  第一层循环外必须要加clips[i][0] <= cur_end, 因为最远的终点cur_end可能会比后面的子区间的起点更靠前，例如[0, 2][4, 8]，起始状态下我们找到2，然后2始终比4小，因此无法完成剪辑，退出while循环
        while (i < n && clips[i][0] <= cur_end) {
            //  遍历每一个起点小于等于cur_end的子区间的终点，找到最远的那个终点，然后将cur_end设置为那个终点
            while (i < n && clips[i][0] <= cur_end) {
                max_end = max(max_end, clips[i][1]);
                i++;
            }
            res++;
            cur_end = max_end;                              //  以max_end作为新的cur_end，继续找起点比cur_end小的所有子区间中终点最远的那一个
            if (max_end >= time) return res;                //  当我们找的起点比cur_end小的子区间中, 最远的终点超过了time, 说明剪辑完毕
        }
        return -1;
    }
};
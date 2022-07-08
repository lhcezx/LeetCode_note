class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> vec(length, 0);         //  初始化差分数组，和原数组长度相同，且元素都为0. 注意: 由于原数组初始状态元素都为0，因此不需要初始化差分数组
        for (vector<int> tmp: updates) {    //  tmp代表每次更新操作的指示，tmp[0]代表启始下标，tmp[1]代表终止下标, tmp[2]代表要增加的元素值
            vec[tmp[0]] += tmp[2];          //  将差分数组的起始位置加inc
            if (tmp[1] + 1 < length) vec[tmp[1] + 1] -= tmp[2];  // 若终止下标的后一个位置j+1仍然比length小，则该位置开始到数组结尾不需要对元素+tmp[2], 因此需要-=tmp[2]
        }
        for (int i = 1; i < length; i++) vec[i] = vec[i - 1] + vec[i];
        return vec;
    }
};

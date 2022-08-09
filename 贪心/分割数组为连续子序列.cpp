//  贪心: 当我们遍历到数字x，如果已经存在序列并且以x-1结尾，那我们应当将x接到x-1的子序列中，而不是创建一个新的序列

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, seqs;     //  freq记录每个数字出现的次数, seqs记录每个序列出现的次数，并将序列的最后一个数字作为键
        for (auto num: nums) {
            freq[num]++;
        }

        for (auto num: nums) {
            if (freq[num] == 0) continue;
            if (seqs[num - 1] > 0) {            //  若存在num-1结尾的子序列，则将num接到序列尾部
                seqs[num - 1]--;
                seqs[num]++;
                freq[num]--;
            } else {                            //  否则需要把num作为子序列的起点创建新的序列
                if (freq[num + 1] == 0 || freq[num + 2] == 0) return false;         //  若已经没有num+1和nums+2，则无法创建序列
                freq[num]--;
                freq[num + 1]--;
                freq[num + 2]--;
                seqs[num + 2]++;
            }
        }
        return true;
    }
};
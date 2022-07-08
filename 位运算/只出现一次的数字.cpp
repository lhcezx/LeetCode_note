class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> count(32);          
        int res = 0;
        int m = 3;
        for (auto num: nums) {                  //  遍历每一个数字
            for (int j = 0; j < 32; j++) {      //  遍历每个数字的每一个二进制位数
                count[j] += num & 1;            //  或运算，判断这一位是不是1, 若是则加上
                num >>= 1;                      //  num数字右移，判断它的下一位
            }   
        }
        //  通过上述遍历，我们统计出了所有数字的每个二进制位中1的数量，若同一数字出现三次，则count[i] % 3 == 0; 若某数字只出现一次，则该为count[i] % 3 == 1;
        for (int j = 0; j < 32; j++) {
            res <<= 1;           // 注意这里必须要先左移再或运算，因为如果先或运算再左移，则最后一位二进制则会多移动一位
            // 由于二进制位要不断左移，因此从最高位count[31-j]开始计算
            res |= count[31 - j] % 3;        //  res的二进制位为0, count[j] % 3代表该位为只出现一次的数字的二进制位数. 若为1, 0|1 = 1. 若为0 0|0 = 0；
            
        }
        return res;
    }
};
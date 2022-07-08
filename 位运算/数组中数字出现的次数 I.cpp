class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int a = 0;   //  数组中唯一出现的数字之一
        int b = 0;   //  数组中唯一出现的数字之一
        int x = 0;   //  a^b的异或结果
        int m = 1;   //  用于找到a^b结果中为1的位数，通过m & (a^b) 来判断
        for (auto num: nums) {
            x ^= num;       //  让nums数组中的数字两两异或，相同的数字异或等于0，因此选择x = 0作为启始，使得最后的结果为剩下的两个不同的数字的异或a^b。
        }
        
        while ((x & m) == 0) {  //  找到a异或b这个二进制中为1的位
            m <<= 1;
        } 

        for(auto num: nums) {
            if ((num & m) == 0) a ^= num;
            else b ^= num;
        }
        return vector<int> {a, b};
    }
};
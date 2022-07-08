class Solution {
public:
    int findNthDigit(int n) {
        long start = 1;         //  启始的数字，如1, 10, 100, 1000...
        long count = 9;         //  某数位的总数, 如一位数1-9共9个数位，二位数10-99共180个数位，100-999共2700个数位
        int digit = 1;          //  表示数字为几位数, 如1, 2, 3, 4..
        while (n > count) {     //  当数位大于前i位数的总数时
            n -= count;
            start *= 10;        //  启始位数乘10，10-100-1000-10000
            digit += 1;         //  数位每次循环加1
            count = start * digit * 9;     // 将前面位数和和当前位数和相加, start*9代表当前位数的数字共有多少，*digit代表每个数字有多少个位数
        }   
        int num = start + (n-1) / digit;   //  通过数位n，这里的n已经减掉了前面比他位数低的数字的位数，因此n是从当前位数开始计算位数. 通过公式计算出位数n所在的数字
        string s = to_string(num);
        return s[(n - 1) % digit] -'0';    // 通过所在数字num找到第n位数，注意这里的n-1, 因为字符串的索引从0开始，例如101中digit = 3, 前面还有一个100, 如果n为5则n%digit = 2, 但字符串101的第二位为1，因此n-1
    }
};
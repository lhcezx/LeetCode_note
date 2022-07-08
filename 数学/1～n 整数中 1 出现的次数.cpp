class Solution {
public:
    int countDigitOne(int n) {
        unsigned int res = 0;
        unsigned int low = 0;            //  初始化时的低位，由于cur初始时为个位，其低位不存在因此为0
        unsigned int cur = n % 10;       //  初始化时计算个位的1的数量，cur为个位数
        unsigned int high = n / 10;      //  初始化时当前位的高位数
        unsigned int digit = 1;          //  10^i，i是指位数
        while (high != 0 || cur != 0) {     // 若高位或当前为数字为0，则代表计算完了整个数字 
            if (cur == 0) res += high * digit;           //  如果当前位数字为0, 为计算当前位数字为1的数字，需要将高位数-1. ex: 2304计算十位数中的1的个数, 则高位数从00-22, 低位数从0-9，根据排列组合可得high*10 = high*digit
            else if (cur == 1) res += high * digit + low + 1;   //  若当前位数字为1，只需要考虑当前位数字为0的情况下1的个数即high * digit再加上当前位为1时低位数的数量. ex: 2314, 2304的1出现次数为high*digit(高位从0-22), 当高位为23时且十位为1时，low从0-4，因此总数为high*digit+low+1
            else res += (high + 1) * digit;              //  若当前位为2-9，则需要考虑当前位为0的情况下1的个数high*digit再加上当前位为1时数字的个数。ex: 2369, 2309的十位数1出现次数为high*digit, 当高位为23且十位为1时，低位可从0-9为10个数，因此high+1*digit
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }   
        return res;
    }
};
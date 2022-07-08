class Solution {
public:
    int divide(int a, int b) {
        if (a == INT_MIN && b == -1) return INT_MAX;   //  防止正数越界
        int res = 0;
        int sign = (a > 0) ^ (b > 0) ? -1: 1;          // ^ 为异或操作符，用于判断ab是否同时为正或者同时为负，这两种情况ab做除法sign都为1

        if (a > 0) a = -a;                             // 这里我们想要让ab同号方便计算，初始情况我们考虑采用abs使其都为正数，但由于如果a或b为负边界最小值-2^31，将其转为正数会越界
        if (b > 0) b = -b;                             // 因此我们将ab都从正数转为负数，这种情况不会越界。
        
        while (a <= b) {                               //  while (a >= b) 是ab都为正数的时候的判断条件，当我们把ab都变为负数的时候此时判断条件为a<=b
            int value = b;
            int k = 1;
            while (value >= 0xc0000000 && a <= value + value) {               //  判断a是否比b * k小，这里的k还没有++，但由于用value+value因此就相当于判断k++后的k。0xc0000000为最小值INT_MIN的一半
                value += value;                        //  b = b * 2;
                if (k > INT_MAX / 2) return INT_MIN;   //  如果k大于INT_MAX的一半那么k+k将越界，直接返回INT_MIN
                k += k;                                //  2的2, 4, 8, 16次方
            }
            a -= value;                    //  a = a - b;
            res += k;
        }
        return sign == 1? res:-res;
    }
};
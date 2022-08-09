//  如果剩下4个石头，无论先手拿1个2个还是3个，都会输，也就是说，当石头剩下的为4的倍数的时候，先手一定会输
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
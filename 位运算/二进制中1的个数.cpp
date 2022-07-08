class Solution {
    int res = 0;
public:
    int hammingWeight(uint32_t n) {
        while (n) {
            n &= n - 1;
            res++;
        }
        return res;
    }
};
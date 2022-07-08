class Solution {
    int res = 0;
public:
    int sumNums(int n) {
        n > 1 && sumNums(n-1);
        res += n;
        return res;
    }
};
class Solution {
public:
    int CountOnes(int x) {
        int counter = 0;
        while (x) {
            x = x & (x - 1);        //  让二进制最左边的一变为0
            counter++;
        }
        return counter;
    }

    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++) {
            res.push_back(CountOnes(i));
        }
        return res;
    }
};
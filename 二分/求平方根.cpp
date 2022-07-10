class Solution {
public:
    //  当某个数不存在时 (比如平方根为小数), 如果我们要找大于等于这个数字的数也就是它右边的整数, 那么用左边界搜索法返回left, 反之如果找小于等于这个数也就是它左边的数，用右边界搜索返回left
    int mySqrt(int x) {
        int left = 0, right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (pow(mid, 2) > x) right = mid - 1;
            if (pow(mid, 2) <= x) left = mid + 1;
        }
        return right;                //  k满足 k^2<=x的最大k值
    }
};
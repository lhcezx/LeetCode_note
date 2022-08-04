class Solution {
public:
    //  f为单调递增函数, x越大, f(x)末尾得到的0越多.      
    long f(long n) {          //  返回给定x的情况下，x的阶乘结尾为0的数量
        long ans = 0;
        while (n) {
            n /= 5;
            ans += n;
        }
        return ans;
    }

    //  找f(x) == target的左边界
    long left_bound(long target) {
        long left = 0, right = LONG_MAX;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (f(mid) >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    //  找f(x) == target的右边界
    long right_bound(long target) {
        long left = 0, right = LONG_MAX;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (f(mid) > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }   

    int preimageSizeFZF(int k) {
        //  右边界 - 左边界 + 1即为满足f(x) = k的x的数量，当x不存在时，right - left = -1，此时+1正好等于0，因此无需单独列出特殊情况
        return int(right_bound(k) - left_bound(k)) + 1;
    }
};
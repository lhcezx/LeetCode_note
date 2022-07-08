class Solution {
public:
    int f(vector<int>& piles, int x) {      //  假设在给定速度的情况下，吃完所有香蕉所需要花费的时间, 速度为x, 花费的时间为f(x), f(x)是关于x的单调递减函数
        unsigned int hours = 0;
        for(int pile: piles){              // 遍历每一堆香蕉
            hours += pile / x;             // 以x的速度吃pile这一堆要花多久
            if (pile % x > 0) {           // 说明除了每小时吃掉x跟香蕉外，剩下的香蕉不足x，但还是要花一小时吃完
                hours++;
            }
        }
        return hours;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;            //  吃香蕉速度的最小和最大速度
        int right = 1000000000 + 1;

        while (left < right) {
        int mid = left + (right - left) / 2;
        if (f(piles, mid) > h) {            //  说明速度太慢了
            left = mid + 1;     
        } else if (f(piles, mid) < h) {
            right = mid;
        } else if (f(piles, mid) == h) {
            right = mid;
        }
    }
        return left;
    }   
};
// 第n个丑数一定是2, 3, 5乘以第n-1个丑数得到的
class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 0, b = 0, c = 0;  // 定义三个指针，分别用于和因子2, 3, 5做乘法运算
        vector<int> dp;           // 用来存放前n个丑数
        dp.push_back(1);          // dp[0] = 1;
        for (int i = 1; i < n; i++) {           //  for循环，分别计算n个丑数
            int dp_i = min(dp[a]*2, min(dp[b]*3, dp[c]*5));  //  第i个丑数为前面a, b, c三个指针指向的丑数分别乘以质因子2, 3, 5中结果最小的那个
            dp.push_back(dp_i);
            if (dp[a]*2 == dp_i) a++;       // 若第i个丑数是a指针指向的丑数乘以2得到的，则a++用于寻找下一个丑数
            if (dp[b]*3 == dp_i) b++;       // 若第i个丑数是b指针指向的丑数乘以3得到的，则b++用于寻找下一个丑数
            if (dp[c]*5 == dp_i) c++;       // 若第i个丑数是c指针指向的丑数乘以5得到的，则c++用于寻找下一个丑数
        }
        return dp.back();
    }
};
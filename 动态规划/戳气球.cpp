//  本题的dp思考路线不能以第一个戳哪一个气球开始，而是应该以最后戳哪一个气球开始。假设三个气球nums[i-1], nums[i], nums[i+1], 原本nums[i-1]与nums[i-2]和nums[i]相邻，nums[i+1]与nums[i]和nums[i+2]相邻，戳破nums[i+1]的分数为nums[i+1]*nums[i]*nums[i+2], 假如我们戳破了nums[i]这个气球，那么nums[i+1]的相邻气球会变成nums[i+2]与nums[i-1](i已经被戳破)，因此这种动态规划的子问题之间会相互影响，所以正向思考不可取。
//  如果我们定义dp[i][j]为开区间(i, j)戳破所有气球所能达到的最大金币数，那么当第k个气球为最后戳破的气球时，k的左右两边分别为nums[i]和nums[j] (开区间，左右边界不会被戳破)，因此当我们对k做选择的时候，k可以从i+1到j-1，每一个k对应的子问题是相互不影响的，因为最后被戳破的气球的左右相邻气球始终都是nums[i]和nums[j]，子问题相互独立，动态规划成立


//  自底向上dp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> new_nums (n + 2);
        new_nums[0] = 1;                                //  左边界  
        new_nums[n + 1] = 1;                            //  右边界
        for (int i = 1; i <= n; i++) {                  //  将原来的nums的0到n-1拷贝到新的nums的1到n
            new_nums[i] = nums[i - 1];
        }
        vector<vector<int>> dp;                         //  dp[i, j]返回开区间(i, j)戳气球能获得的最大金币数
        dp.assign(n + 2, vector<int> (n + 2));          //  这里是n+2的原因是[0, n-1]的闭区间对应(-1, n)的开区间，对应n+2个气球，这里的气球编号从0到n-1变为从1到n
        for (int i = 0; i < n + 2; i++) {               //  base case，再次强调，(i, j)为开区间
            for (int j = 0; j <= i + 1 && j < n + 2; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = n + 1; i >= 0; i--) {              //  计算dp[i][j]前需要计算dp[k][j], k在i后面，因此每列j的i应当从下往上计算
            for (int j = i + 2; j < n + 2; j++) {       //  计算dp[i][j]前需要计算dp[i][k], k小于j, 因此每行i的j应当从左向右计算
                for (int k = i + 1; k <= j - 1; k++) {  //  对最后戳破哪一个气球做选择
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + new_nums[i] * new_nums[k] * new_nums[j]);
                }
            }
        }
        return dp[0][n + 1];
    }
};



//  自顶向下dp
class Solution {
    vector<vector<int>> memo;                         //  memo[i, j]返回开区间(i, j)戳气球能获得的最大金币数
public:
    //  函数返回在开区间(i, j)中所能获得最大金币数
    int dp(vector<int>& nums, int i, int j) {
        if (i >= j - 1) return 0;                     //  base case 没有气球可戳
        if (memo[i][j] != -1) return memo[i][j];
        int res = INT_MIN;
        for (int k = i + 1; k <= j - 1; k++) {
            int subProb = dp(nums, i, k) + dp(nums, k, j) + nums[i] * nums[k] * nums[j];
            res = max(res, subProb);
        }
        return memo[i][j] = res;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> new_nums (n + 2);
        new_nums[0] = 1;                                  
        new_nums[n + 1] = 1;                           
        for (int i = 1; i <= n; i++) {                 
            new_nums[i] = nums[i - 1];
        }
        memo.assign(n + 2, vector<int> (n + 2, -1));      
        return dp(new_nums, 0, n + 1);
    }
};
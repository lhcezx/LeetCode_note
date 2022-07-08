//  本质问题是动态规划，将BST的生成区间从[1,n]分别拆分直到区间为1或者0，返回子树的种类为1，然后递归的计算子树区间长度为2,3,4......时bst的种类
class Solution {
    vector<vector<int>> memo;
public:
    int count(int low, int high) {  //  返回以low为起始以high为终止的bst树的种类
    //  当区间为空时，代表nullptr, 返回1. 这里不返回0因为另一颗子树的排列组合不为0，后面会做乘法运算, 若返回0则乘法结果等于0; 当low == high 区间为1时，一个节点只能构成一种子树
        if (low >= high) return 1;  
        if (memo[low][high] != 0) return memo[low][high];
        int res = 0;
        //  遍历从low到high，记录以i节点为根节点时，bst的种类有多少
        for (int i = low; i <= high; i++) {
            int left = count(low, i - 1);           //  左边的排列组合种类，例如(12345中i = 3, 左边为12, 右边为45)
            int right = count(i + 1, high);         //  右边的排列组合种类
            res += left * right;                    //  左边的排列组合种类乘以右边的种类，就是以i为根节点时左右的种类
        }
        memo[low][high] = res;
        return res;
    }       

    int numTrees(int n) {
        memo.resize(n + 1, vector<int>(n + 1));     //  记录以low为起点，high为终点的bst树的种类，防止重复计算子问题
        return count(1, n);
    }
};
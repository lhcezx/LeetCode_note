class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        res.resize(n, vector<int>(n));
        int t = 0, b = n - 1, l = 0, r = n - 1;      //  定义上下左右四个边界值
        int num = 1;
        while (num <= n*n) {  
            for (int i = l; i <= r; i++) res[t][i] = num++;    //  从顶上一行从左上至右上遍历
            t++;
            for (int i = t; i <= b; i++) res[i][r] = num++;    //  从右边一列从右上至右下遍历       
            r--;     
            for (int i = r; i >= l; i--) res[b][i] = num++;    //  从底下一行从右下至左下遍历
            b--;
            for (int i = b; i >= t; i--) res[i][l] = num++;    //  从左边一列从左下至左上遍历
            l++;
        }
        return res;
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int t = 0, b = matrix.size() - 1, l = 0, r = matrix[0].size() - 1;      //  定义上下左右四个边界值
        while (true) {  
            for (int i = l; i <= r; i++) res.push_back(matrix[t][i]);    //  从顶上一行从左上至右上遍历
            t++;
            if (t > b) break;
            for (int i = t; i <= b; i++) res.push_back(matrix[i][r]);    //  从右边一列从右上至右下遍历            
            r--; 
            if (r < l) break;
            for (int i = r; i >= l; i--) res.push_back(matrix[b][i]);    //  从底下一行从右下至左下遍历
            b--;
            if (b < t) break;
            for (int i = b; i >= t; i--) res.push_back(matrix[i][l]);    //  从左边一列从左下至左上遍历
            l++;
            if (l > r) break;
        }
        return res;
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
        while (true) {
            for (int i = left; i <= right; i++) res.push_back(matrix[top][i]);   //  从左上向右上遍历
            if (++top > bottom) break;                                          //  最上面的一行遍历完比，将top++不再遍历那行
            for (int i = top; i <= bottom; i++) res.push_back(matrix[i][right]); //  从右上向右下遍历
            if (--right < left) break;
            for (int i = right; i >= left; i--) res.push_back(matrix[bottom][i]);  //  从右下向左下遍历
            if (--bottom < top) break;
            for (int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);    //  从左下往左上遍历
            if (++left > right) break;
        }
        return res;
    }
};
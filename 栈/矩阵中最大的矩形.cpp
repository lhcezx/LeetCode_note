class Solution {
public:
    int maximalhistogram(vector<int>& heights) {
        int max_area = INT_MIN;
        stack<int> s;
        s.push(-1);
        for (int i = 0; i < heights.size();) {
            if (s.top() == -1 || heights[s.top()] <= heights[i]) s.push(i++);
            else {
                int high = heights[s.top()];            //  以栈顶元素的柱高作为高
                s.pop();
                int width = i - s.top() - 1;            //  i为右边比栈顶元素矮的柱子，s.top()为左边比栈顶元素矮的柱子
                max_area = max(max_area, high * width);
            }
        }
        while (s.top() != -1) {
            int high = heights[s.top()];
            s.pop();
            int width = heights.size() - s.top() - 1;
            max_area = max(max_area, high * width);
        }
        return max_area;
    }

    int maximalRectangle(vector<string>& matrix) {
        if (matrix.size() == 0) return 0;
        int res = 0;
        vector<int> heights(matrix[0].size());
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '0') heights[j] = 0;    
                else heights[j] += matrix[i][j] - '0';      // 将每一行的1在每一列累加起来，例如第三行我们可以看做[3, 1, 3, 2, 2]的直方图，一旦遇到0，直接将该列重置为0，重新计算直方图高度
            }
            res = max(res, maximalhistogram(heights));      // 以第i行为直方图的底边，计算最大直方图的面积
        }
        return res;
    }
};
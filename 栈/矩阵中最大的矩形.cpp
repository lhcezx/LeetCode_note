//  单调栈
class Solution {
public:
    int largestArea(vector<int>& heights) {
        int max_area = 0;
        int left, right, width, height;
        stack<int> stk;
        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int top = stk.top();
                stk.pop();
                left = stk.empty() ? -1 : stk.top();
                right = i;
                max_area = max(max_area, (right - left - 1) * heights[top]);
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            int top = stk.top();
            stk.pop();
            left = stk.empty() ? -1 : stk.top();
            right = heights.size();
            max_area = max(max_area, (right - left - 1) * heights[top]);
        }
        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int max_area = 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '0') heights[j] = 0;        // 将每一行的1在每一列累加起来，例如第三行我们可以看做[3, 1, 3, 2, 2]的直方图，一旦遇到0，直接将该列重置为0，重新计算直方图高度
                else heights[j] += 1;
            }
            max_area = max(max_area, largestArea(heights));     // 以第i行为直方图的底边，计算最大直方图的面积
        }
        return max_area;
    }
};
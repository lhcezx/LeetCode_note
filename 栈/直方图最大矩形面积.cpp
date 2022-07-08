//  本题的主要思路: 找到柱子i的左右两边分别第一个比它矮的柱子，然后根据下标做差作为宽度，以柱子i的高度为高计算矩阵面积
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = INT_MIN;
        stack<int> s;
        s.push(-1);                                                             //  -1代表数组第一个元素的左边
        for (int i = 0; i < heights.size();) {
            int idx = s.top();                                                  //  当前栈顶元素的下标位置
            if (idx == -1 || heights[i] >= heights[idx]) s.push(i++);             //  当栈为空或入栈元素大于等于栈顶元素的高度时
            else {
                int high = heights[idx];                                        //  当前栈顶元素的柱高
                s.pop();                                                        //  循环pop掉所有比要入栈元素高的柱子同时计算最大面积，也就是入栈元素就是比栈内矮的元素的右边界
                max_area = max(max_area, (i - s.top() - 1) * high);             //  计算矩形最大面积，计算方式为入站元素作为右边界(栈顶元素右边第一个比它矮的柱子), 栈顶元素出栈后的栈顶元素为左边界(栈内也就是它左边第一个比它矮的柱子)，i为右边界，pop后的s.top()为左边界
            }
        }
        //  由于循环遍历结束后，栈内仍然保留有元素，说明还没找到这些元素的右边界，因此我们可以考虑为这些元素的右边界其实就是数组的最后一个元素的右边heights.size()
        while (s.top() != -1) {
            int high = heights[s.top()];
            s.pop();
            int width = (heights.size() - s.top() - 1);
            max_area = max(max_area, width * high);
        }
        return max_area;
    }
};
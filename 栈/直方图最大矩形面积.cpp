//  未优化版
//  分别找到每一根柱子左右边界，然后计算最大面积
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        vector<int> left(heights.size()), right(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) stk.pop();     //  将前面所有比它高的都pop掉，找到heights[i]左边第一根比它小的柱子
            left[i] = stk.empty()? -1: stk.top();                                   //  若栈为空，说明右边没有比它矮的柱子，则右边界为-1
            stk.push(i);
        }

        stk = stack<int>();
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) stk.pop();     //  将后面所有比它高的都pop掉，找到heights[i]右边第一根比它小的柱子
            right[i] = stk.empty()? heights.size(): stk.top();                      //  若栈为空，说明右边没有比它矮的柱子，则右边界为heights.size()
            stk.push(i);
        }

        int max_area = 0;
        for (int i = 0; i < heights.size(); i++) {                                  //  计算最大面积
            int width = right[i] - left[i] - 1;
            int high = heights[i];
            max_area = max(max_area, width * high);
        }
        return max_area;
        
    }
};



//  优化版
//  本题的主要思路: 找到柱子i的左右两边分别第一个比它矮的柱子，然后根据下标做差作为宽度，以柱子i的高度为高计算矩阵面积
//  左边第一根比栈顶元素矮的柱子，也就是它的前一根柱子。注意这里左边的柱子有可能和栈顶元素高度相等，此时栈顶元素求出来的不是正确的最大面积，但是我们会继续计算左边这根柱子的最大面积，此时会返回正确的最大面积。
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = INT_MIN;
        stack<int> stk;                             
        for (int i = 0; i < heights.size(); i++) {                             
            //  严格单调递减的单调栈
            while (!stk.empty() && heights[i] < heights[stk.top()]) {                  //  当要入栈的元素比栈顶元素小时
                int right = i;                                                         //  右边界为右边第一根比栈顶元素矮的柱子
                int high = heights[stk.top()];
                stk.pop();
                int left = stk.empty()? -1: stk.top();                                 //  左边界为栈顶元素出站后的栈顶元素, 若出栈后栈为空, 则左边界为-1
                max_area = max(max_area, (right - left - 1) * high);                 
            }
            stk.push(i);
        }
        //  由于循环遍历结束后，栈内仍然保留有元素，说明还没找到这些元素的右边界，因此我们可以考虑为这些元素的右边界其实就是数组的最后一个元素的右边heights.size()
        while (!stk.empty()) {
            int right = heights.size();
            int high = heights[stk.top()];
            stk.pop();
            int left = stk.empty()? -1: stk.top();
            max_area = max(max_area, (right - left - 1) * high);
        }
        return max_area;
    }
};
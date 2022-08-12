//  动态规划

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        vector<int> left_high(n, 0), right_high(n, 0);                              //  记录每个索引对应的柱子的左边最高的柱子和右边最高的柱子
        left_high[0] = height[0];
        right_high[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) left_high[i] = max(left_high[i - 1], height[i]);
        for (int i = n - 2; i >= 0; i--) right_high[i] = max(right_high[i + 1], height[i]);
        for (int i = 1; i < n - 1; i++) {
            res += min(left_high[i], right_high[i]) - height[i];                    //  索引i位置能保存的雨水为左边最高的柱子和右边最高的柱子中较矮柱子的高度减去当前i位置柱子的高度
        }
        return res;
    }
};


//  双指针解法: max_left保存[0:left]的最大值, max_right保存[right:n-1]的最大值
//  当max_left < max_right时，对于left而言max_right对它不一定是右边的最大值，但max_left一定是左边的最大值，left位置最多能接的水只能为max_left - height[left], right同理, 因此当确定较小max以后，更新其对应的指针并将指针后移

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        int max_left = 0, max_right = 0;
        while (left < right) {
            max_left = max(max_left, height[left]);
            max_right = max(max_right, height[right]);
            if (max_left < max_right) {
                res += max_left - height[left++];
            } else {
                res += max_right - height[right--];
            }
        }
        return res;
    }
};


//  单调栈解法，需要保证栈内至少有两个元素, 将栈顶元素作为要计算的对象，栈顶下面的元素作为left, 当前遍历到的元素作为right, 保证栈内元素单调递减(栈内存的是索引，单调递减的是索引对应的高度)
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int cur = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int left = stk.top();
                int width = i - left - 1;
                int high = min(height[left], height[i]) - height[cur];
                res += width * high;
            }
            stk.push(i);
        }
        return res;
    }
};

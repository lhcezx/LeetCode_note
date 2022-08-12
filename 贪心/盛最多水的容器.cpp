class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        while (left < right) {
            int left_high = height[left];
            int right_high = height[right];
            int width = right - left;
            res = max(res, min(left_high, right_high) * width);
            //  移动较低的一边，因为移动较低的一边，边有可能会变高，因此面积可能会增大。但如果移动较高的一边，只会减小宽度，因为变得更高对面积没有影响(取决于较低的一边), 如果变低则会减小面积。
            if (left_high < right_high) left++;
            else right--;
        }
        return res;
    }
};
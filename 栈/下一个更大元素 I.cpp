//  我们寻找的是某个元素的右侧第一个比它大的元素，元素每次入栈时会将比它小的元素全部弹出，我们的顺序是从后往前入栈，栈的特性为后入先出，因此栈顶元素即为最靠近当前元素且大于当前元素的元素(单调栈)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> hash_map;                               //  用于保存每个num2的后面第一个比它大的值
        stack<int> stk;
        for (int i = nums2.size() - 1; i >= 0; i--) {                   //  从后向前遍历
            while (!stk.empty() && nums2[i] >= stk.top()) stk.pop();    //  i指针不断向前移动，代表i在栈中元素的索引前面，如果它比栈内元素大，那么栈内元素一定不是i前面元素的第一个大的元素，因此全部出栈
            hash_map[nums2[i]] = stk.empty()? -1: stk.top();          //  nums2[i]入栈前会将所有比它小的值出栈，直到找到离他最近的比它大的元素，如果栈最后为空则说明没有比他更大的，返回-1
            stk.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = hash_map[nums1[i]];
        }
        return nums1;
    }
};
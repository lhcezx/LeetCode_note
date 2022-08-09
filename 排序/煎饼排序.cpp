//  将每个子数组arr[0:i]中的最大元素先翻转到头部，也就是翻转arr[0:max_element_idx]. 然后再翻转整个子数组arr[0:i]，将其翻转到子数组尾部尾部.
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        for (int i = n - 1; i > 0; i--) {
            int idx = max_element(arr.begin(), arr.begin() + i + 1) - arr.begin();          //  找到从起始到arr[i]的最大值
            if (idx == i) continue;                                                         //  如果这个最大的下标已经在子数组的的结尾
            reverse(arr.begin(), arr.begin() + idx + 1);                                    //  将从0到最大值位置的子数组翻转, 可以将最大值翻转到数组的开头
            reverse(arr.begin(), arr.begin() + i + 1);                                      //  再次翻转，将子数组中的最大值从头部翻转到尾部
            res.push_back(idx + 1);
            res.push_back(i + 1);
        }
        return res;
    }
};
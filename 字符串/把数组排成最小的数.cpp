class Solution {
public:
    int GetMiddle(vector<string>& str, int low, int high) {
        string tmp = str[low]; // 快排的基准值
        while (low < high) {
            while (low < high && str[high] + tmp >= tmp + str[high]) high--;
            str[low] = str[high]; // 把右边比基准值小的值赋给基准值位置，此时基准值没有移动到high位置，但我们默认基准值在high
            while (low < high && str[low] + tmp <= tmp + str[low]) low++;
            str[high] = str[low]; // 在high位置的基准值用low位置的更大的值来替换，此时基准值应当移动到low
            str[low] = tmp;
        }
        return low; //返回基准值的位置
    }
    void QuickSort(vector<string>& str, int l, int r) {
        if (l >= r) return;
        int mid = GetMiddle(str, l, r);
        QuickSort(str, l, mid - 1);
        QuickSort(str, mid + 1, r);
    }
        

    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for (int i = 0; i < nums.size(); i++) {
            strs.push_back(to_string(nums[i]));
        }
        QuickSort(strs, 0, strs.size() - 1);
        for (string s: strs) {
            res.append(s);
        }
        return res;
    }

};
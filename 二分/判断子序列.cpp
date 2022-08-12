//  双指针
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) i++;
            j++;
        }
        return i == s.size();
    }
};



//  二分
class Solution {
public:
    //  左边界查找，找到大于target的第一个元素的下标
    int left_bound(vector<int>& vec, int target) {
        int sz = vec.size();
        int left = 0, right = sz - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (vec[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> idx;            //  对序列T中每个字符都将其索引保存起来用于快速二分查找
        int j = 0;      //  t字符串上的指针
        for (int i = 0; i < t.length(); i++) idx[t[i]].push_back(i);
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (!idx.count(c)) return false;
            int pos = left_bound(idx[c], j);             //  找到在j指针位置后面的c的下标，如果c出现在j前面，那么left会变成idx[c].size，无法构成子序列
            if (pos == idx[c].size()) return false;
            j = idx[c][pos] + 1;
        }
        return true;
    }
};
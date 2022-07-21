class Solution {
    vector<vector<int>> dp_table;                                     //  用来记录指针i，j当前所在位置下转换word1到word2所需的最小操作数
public:
    int dp(string& word1, int i, string& word2, int j) {              //  返回word1[0:i]转换成word2[0:j]所有的最少数
        //  base case
        if (i == -1) return j + 1;                                    //  单词word1指针遍历完了所有word1的字母，此时需要将word2从[0:j]部分的字母插入到word1前面, 完成转换，因此剩余次数需要j+1次
        if (j == -1) return i + 1;                                    //  单词word2指针遍历完了所有word2的字母，此时需要将word1从[0:i]部分的字母全部删除，完成转换，剩余操作次数为i+1次
        if (word1[i] == word2[j]) {
            return dp(word1, i - 1, word2, j - 1);                    //  当指针ij指向的字母相同时，我们无需做任何操作，并将i, j指针前移
        }
        if (dp_table[i][j] != INT_MAX) return dp_table[i][j];
        // 当word1[i] != word2[j]时，我们有三种选择: 删除i字符; 将i字符用j字符替换; 将i字符后面插入j字符
        int del = dp(word1, i - 1, word2, j) + 1;                     //  将i位置的字符删除后，i指针前移
        int replace = dp(word1, i - 1, word2, j - 1) + 1;             //  将i位置的字符用j位置的字符替换后, i和j指针都前移
        int insert = dp(word1, i, word2, j - 1) + 1;                  //  将j位置的字符插入到i指针后面后，j指针前移
        return dp_table[i][j] = min(del, min(replace, insert));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        dp_table.assign(n, vector<int> (m, INT_MAX));
        return dp(word1, n - 1, word2, m - 1);                        //  两个指针初始位置都在word1和word2的尾部
    }
};
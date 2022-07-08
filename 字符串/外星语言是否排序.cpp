class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> order_idx(26);
        for (int i = 0; i < order.size(); i++) {                //  将外星文字典序中每一个字母保存其位置信息
            order_idx[order[i] - 'a'] = i; 
        }
        for (int i = 1; i < words.size(); i++) {
            bool valid = false;
            for (int j = 0; j < words[i - 1].size() && j < words[i].size(); j++) {      //  我们只遍历前一个单词和后一个单词的相同长度的部分
                int prev = order_idx[words[i - 1][j] - 'a'];
                int cur = order_idx[words[i][j] - 'a'];
                if (prev < cur) {                               //  如果前一个单词和后一个单词相同位置的字典序不同，且后一个大于前一个，则valid
                    valid = true;
                    break;
                } else if (prev > cur) {
                    return false;
                }
            }
            if (!valid) {                                       //  如果从头到尾重复部分的单词字典序都是相同的，意为重复部分单词是相同的
                if (words[i-1].size() > words[i].size()) return false;          //  如果前一个单词比后一个单词长
            }                     
        }
        return true;
    }
};
//  首先遍历字符串，记录左括号和右括号的数量差，并且记录左右括号的相对值
//  回溯过程中，若左右括号数量差为0，则判断是否合法，若合法则保存到res. 每次遇到左括号时，做选择是否要删除，右括号同理
//  删除s[i]位置的字符表现为将原本的s.substr(0, i) + s.substr(i + 1)，注意s不能是引用。删除后的字符串我们仍然从i开始遍历，因为后面的i变到当前i的位置上了
class Solution {
    vector<string> res;
    unordered_set<string> set;
public:
    bool isValid(string& str) {
        int left = 0, right = 0;
        for (auto c: str) {
            if (c == '(') left++;
            if (c == ')') right++;
            if (left < right) return false;
        }
        return left == right;
    }

    void backtrack(string s, int start, int left2del, int right2del) {
        int n = s.length();
        if (left2del == 0 && right2del == 0) {
            if (isValid(s)) {
                if (!set.count(s)) {
                    res.push_back(s);
                    set.insert(s);
                }
            }
            return;
        }
        //  遍历每一个位置，判断是否要删除i位置上的左括号或右括号
        for (int i = start; i < n; i++) {
            if (left2del + right2del > n - i) return;       //  当要删除的左右括号比剩下的字符串长度要长时，必不可能删完，直接返回
            if (s[i] == '(' && left2del > 0) backtrack(s.substr(0, i) + s.substr(i + 1), i, left2del - 1, right2del);       //  当待删除左括号数量大于0时，我们可以选择删除或者不删除这个括号
            if (s[i] == ')' && right2del > 0) backtrack(s.substr(0, i) + s.substr(i + 1), i, left2del, right2del - 1);      //  当待删除右括号数量大于0时，我们可以选择删除或者不删除这个括号
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int left2del = 0, right2del = 0;            //  合法的字符串中左括号和右括号数量是相等的，因此我们需要记录不相等的差值，并确定是哪边的括号更多
        for (auto c: s) {
            if (c == '(') left2del++;
            else if (c == ')') {
                if (left2del == 0) right2del++;
                else left2del--;
            }
        }
        backtrack(s, 0, left2del, right2del);
        return res;
    }   
};
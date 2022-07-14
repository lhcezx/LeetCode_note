//  无for循环版本

class Solution {
    vector<string> res;
public:
    void backtrack(int n, int left, int right, string& onPath) {        //  放n个括号，代表左括号有n个，右括号也有n个，这样才合法。并且在每个位置i时，[0, i]中左括号的总数一定大于右括号的数量
        if (left < 0 || right < 0) return;
        if (right < left) return;                                       //  如果右括号放的比左括号多，则不合法，返回
        if (left == 0 && right == 0) {
            res.push_back(onPath);
            return;
        }
        onPath.push_back('(');
        backtrack(n, left - 1, right, onPath);
        onPath.pop_back();

        onPath.push_back(')');
        backtrack(n, left, right - 1, onPath);
        onPath.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string onPath = "";
        backtrack(n, n, n, onPath);
        return res;
    }
};



//  有for循环版本

class Solution {
    vector<string> res;
    vector<char> dir {'(', ')'};
public:
    void backtrack(int n, int left, int right, string& onPath) {        //  放n个括号，代表左括号有n个，右括号也有n个，这样才合法。并且在每个位置i时，[0, i]中左括号的总数一定大于右括号的数量
        if (left < 0 || right < 0) return;
        if (right < left) return;                                       //  如果右括号放的比左括号多，则不合法，返回
        if (left == 0 && right == 0) {
            res.push_back(onPath);
            return;
        }
        for (auto a: dir) {
            onPath.push_back(a);
            if (a == '(') {
                backtrack(n, left - 1, right, onPath);
            } else {
                backtrack(n, left, right - 1, onPath);
            }
            onPath.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string onPath = "";
        backtrack(n, n, n, onPath);
        return res;
    }
};
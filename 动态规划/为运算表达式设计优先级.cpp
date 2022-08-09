class Solution {
    unordered_map<string, vector<int>> memo;
public:
    //  函数返回expression表达式所能计算出的结果有哪些，并将其全部保存在vector<int>中
    vector<int> diffWaysToCompute(string expression) {
        if (memo.count(expression)) return memo[expression];
        vector<int> res;
        int n = expression.size();
        for (int i = 0; i < n; i++) {
            char c = expression[i];
            //  以每个运算符作为分割，分别计算左右两边的表达式能够得到的所有结果，最后再将所有结果合并
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));          
                vector<int> right = diffWaysToCompute(expression.substr(i + 1, n - i - 1));
                for (int a: left) {
                    for (int b: right) {
                        if (c == '+') res.push_back(a + b);
                        else if (c == '-') res.push_back(a - b);
                        else res.push_back(a * b);
                    }
                }                
            }
        } 
        //  若res为空，则表达式中不存在运算符
        if (res.empty()) res.push_back(stoi(expression));
        return memo[expression] = res; 
    }
};
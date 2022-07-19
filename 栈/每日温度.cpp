class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<int> s;
        for (int i = 0; i < temperatures.size(); i++) { 
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {     //  当栈非空且栈顶元素对应的温度小于当前温度时
                int idx = s.top();
                res[idx] = i - idx;
                s.pop();
            }
            s.push(i);                    //  当栈为空时或者栈顶元素对应温度大于当前温度时
        }
        return res;
    }
};



//  因为是找某个温度后面第一个比它高的温度，因此从后向前更容易理解，更加符合单调栈后入先出的特性
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size());
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!stk.empty() && temperatures[i] >= temperatures[stk.top()]) stk.pop();
            res[i] = stk.empty()? 0: stk.top() - i;
            stk.emplace(i);
        }
        return res;
    }
};
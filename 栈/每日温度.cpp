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
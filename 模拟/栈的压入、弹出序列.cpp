class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> simul;
        int size = pushed.size();
        int j = 0;
        for (int i = 0; i < size; i++) {
            simul.push(pushed[i]);
            while (!simul.empty() && simul.top() == popped[j]) {        //  判断栈顶元素和出栈元素是否相等，若相等则出栈，注意这里应当用while循环而非if
                simul.pop();
                j++;
            }
        }
        return simul.empty();
    }
};
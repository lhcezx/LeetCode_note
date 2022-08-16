//  辅助栈，min_stk为单调递减栈，栈顶元素为最小值，只有当入站元素小于等于栈顶元素时，才会入栈
class MinStack {
    stack<int> stk;
    stack<int> min_stk;
public:
    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        if (min_stk.empty() || val <= min_stk.top()) {
            min_stk.push(val);
        }
    }
    
    void pop() {
        //  如果要出栈的元素恰好是当前的最小元素也就是min_stk栈顶元素，那么也将min_stk出栈
        if (stk.top() == min_stk.top()) min_stk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack {
    stack<int> s1, s_min;
public:
    /** initialize your data structure here. */
    MinStack() {
        s_min.push(INT_MAX);
    }
    
    void push(int x) {
        s_min.push(::min(s_min.top(), x));
        s1.push(x);
    }
    
    void pop() {
        s1.pop();
        s_min.pop();
    }
    
    int top() {
        return s1.top();
    }

    int min() {
        return s_min.top();
    }
};
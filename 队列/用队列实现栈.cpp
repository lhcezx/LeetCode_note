class MyStack {
    queue<int> q;
public:
    MyStack() {
    }
    
    void push(int x) {
        int sz = q.size();
        q.push(x);
        //  将最后插入的元素放到队首
        for (int i = 0; i < sz; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int tmp = q.front();
        q.pop();
        return tmp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
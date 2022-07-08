class MaxQueue {
    queue<int> q;
    deque<int> dq_max;      //  用一个双端队列动态维护最大值
public:
    MaxQueue() { }
    
    int max_value() {
        if (dq_max.empty()) return -1;
        return dq_max.front();
    }
    
    void push_back(int value) {
        q.push(value);
            while (!dq_max.empty() && value > dq_max.back()) dq_max.pop_back();  //  双端队列中删除所有比压入的值小的值
        dq_max.push_back(value);
        
    }
    
    int pop_front() {
        if (q.empty()) return -1;
        int front = q.front();
        if (front == dq_max.front()) dq_max.pop_front();  //  如果队头元素出队，则需要判断出队元素是不是最大值，如果是则需要将双端队列的队首元素删除
        q.pop();
        return front;
    }
};
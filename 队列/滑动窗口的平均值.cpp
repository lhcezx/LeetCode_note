class MovingAverage {
    queue<int> q;
    int size;
    double avg = 0.;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        if (q.size() == 0) {
            q.push(val);
            avg = val / 1.0;
        }
        else if (q.size() != size) {
            avg = avg * q.size() + val;
            q.push(val);
            avg /= q.size();
        } else if (q.size() == size) {
            avg = avg * q.size() - q.front() + val;
            q.pop();
            q.push(val);
            avg /= q.size();
        }
        return avg;
    }   
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
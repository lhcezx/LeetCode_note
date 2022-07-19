class MedianFinder {
    priority_queue<int, vector<int>, less<int>> maxheap; // 最大堆, 用于存储左边较小一半的元素, 堆顶为最大值
    priority_queue<int, vector<int>, greater<int>> minheap; // 最小堆，用于存储右边较大一半的元素，堆顶为最小值
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        // 当最大堆和最小堆中元素个数相等时，应向最小堆插入元素。实际做法是将元素插入最大堆，然后将其堆顶元素插入最小堆，因为我们需要判断是否这个新元素比最大堆中的元素都要大，如果是它就在堆顶直接输出，如果不是那么将原本最大堆的最大元素输出给最小堆
        if (maxheap.size() == minheap.size()) {  // 此时应向最小堆中插入元素
            maxheap.push(num);  // 做法是向最大堆插入，然后将其堆顶元素输出给最小堆
            minheap.push(maxheap.top()); maxheap.pop();
        } else {
            minheap.push(num);
            maxheap.push(minheap.top()); minheap.pop();
        }
    }
    
    double findMedian() {
        if (maxheap.size() == minheap.size()) return (minheap.top() + maxheap.top())*1.0 / 2;
        else return minheap.top()*1.0;
    }
};


//
class MedianFinder {
    priority_queue<int> A;                                         //  大顶堆
    priority_queue<int, vector<int>, greater<int>> B;              //  小顶堆
    int count = 0;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (count == 0) {
            A.push(num);
            count++;
            return;
        }
        if (count % 2 == 0) {
            B.push(num);
            int top = B.top();
            B.pop();
            A.push(top);
            count++;
        } else {
            A.push(num);
            int top = A.top();
            A.pop();
            B.push(top);
            count++;
        }
    }
    
    double findMedian() {
        if (count % 2 == 0) {
            return (A.top() + B.top()) / 2.0;
        } else {
            return A.top() * 1.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;         
        if (nums.empty()) return res;           
        deque<int> dq;
        dq.push_back(nums[0]);               //  首先将num中第一个元素放入队列
        // 窗口未开始滑动
        for (int i = 1; i < k; i++) {        //  将第一个滑动窗口[0, k) 内的元素按照从大到小放入队列，此时窗口还未开始滑动
        //  将所有比nums[i]小的元素从队列中删除后将nums[i]插入到队尾，因为i位置前比它小的元素将不再有任何意义，即便窗口开始滑动，nums[i]前的值也不会是窗口最大值，因为nums[i]比他们值更大
            while (!dq.empty() && nums[i] > dq.back()) {       
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        res.push_back(dq[0]);

        // 窗口开始滑动
        for (int i = k; i < nums.size(); i++) {
            if (nums[i - k] == dq[0])  dq.pop_front(); // 若队列中的最大值在窗口滑动后被滑过，则删除队首元素
            while (!dq.empty() && nums[i] > dq.back()) dq.pop_back();
            dq.push_back(nums[i]);
            res.push_back(dq[0]);
        }
        return res;
    }
};
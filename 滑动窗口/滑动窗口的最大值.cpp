//  使用单调队列的数据结构是为了满足滑动窗口的性质，具有时序性，窗口左边的元素会被先弹出去，先入先出; 为了保证队列的单调递减性质，需要将比队首小的元素全部pop出去，因此要从队尾pop而普通的队列无法满足这个性质，所以需要用双端队列。

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        //  窗口还未开始滑动，构建单调双端队列，从队首到队尾递减
        for (int i = 0; i < k - 1; i++) {
            while (!dq.empty() && nums[i] > dq.back()) dq.pop_back();
            dq.push_back(nums[i]);
        }

        //  形成窗口了，构建左右指针开始滑动
        for (int right = k - 1; right < nums.size(); right++) {
            int left = right - k + 1;
            while (!dq.empty() && nums[right] > dq.back()) dq.pop_back();           //  即将入队的元素会pop出去所有比它小的元素然后入队尾, 保证严格单调递减. 队内元素排在即将入队的元素的索引前面，并且一定在滑动窗口内, 如果即将入队的元素比它们大，那么它们一定不会是滑动窗口的最大值，因此全部pop
            dq.push_back(nums[right]);
            res.push_back(dq.front());                                              //  推入队首元素也就是当前窗口的最大元素
            if (dq.front() == nums[left]) dq.pop_front();                           //  如果队首元素等于滑动窗口左指针，那么将其pop掉
        }
        return res;
    }
};
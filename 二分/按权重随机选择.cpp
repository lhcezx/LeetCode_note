class Solution {
     vector<int> presum;
public:
    //  当元素不存在的时候，左边界搜索二分会返回大于等于target的最小索引。假设我们有left = 0, nums[left] = 1, right = 1, nums[right] = 5, target = 3。此时的target不存于数组中，二分判别时, 0 + 1 / 2 = 0，也就是当left和right相邻时，mid等于left。此时的nums[mid] < target, left = mid + 1 = 1。这时left == right了，nums[mid] > target了，然后right = mid - 1 = 0. 我们可以看出，大于target的最大索引是left。
    int binray_search(vector<int>& presum, int target) {
        int left = 0, right = presum.size() - 1; 
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (presum[mid] >= target) {
                right = mid - 1; 
            } else if (presum[mid] < target) {
                left = mid + 1;
            }
        }
        return left;
    }

    Solution(vector<int>& w) {
        presum.resize(w.size() + 1);
        for (int i = 1; i < presum.size(); i++) {
            presum[i] = presum[i - 1] + w[i - 1];           //  前缀和数组
        }
        
    }
    
    int pickIndex() {
        int rand_num = rand() % presum.back() + 1;          //  这里需要注意的是随机数从[1, presum.back()]选取的，加入从[0, presum.back()]选，假如随机数为0，我们就会从presum中找到第一个元素0的下标为0, 然而0在presum的存在只是为了方便使用presum[i] = presum[i - 1] + w[i - 1]这个公式，因此它是无意义的。从数学的角度分析，可以将presum中的数字理解为下标出现的概率(不是非常准确，只是理解的角度) 没有一个下标的概率会是0，并且每个随机数都是整数，因此从1开始
        int idx = binray_search(presum, rand_num);
        return idx - 1;                                     //  前缀和数组中多了一个0的前缀和，下标为0，因此后面的前缀和下标都加1了
    }
};
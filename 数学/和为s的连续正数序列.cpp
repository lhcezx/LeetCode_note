class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res; 
        int sum = 3;
        int left = 1;       //  滑动窗口的左指针
        int right = 2;      //  滑动窗口的右指针      
        while (left < right) {     // 当达到一定的临界值时, 无论如何左移指针，sum将始终大于target，知道left = right的时候会退出。
            if (sum == target) {        
                vector<int> tmp;
                for (int i = left; i <= right; i++) {      
                    tmp.push_back(i);
                }
                res.push_back(tmp);
            }      
            
            if (sum >= target) {     //  如果窗口内的和比目标值大或者相等的情况下，则需要右移左指针减小区间范围。相等时应当减小区间，若增大区间则陷入无限循环。
                sum -= left;        //  先将left值从sum中删除，再将left+1
                left += 1;
            } else if (sum < target) {
                right += 1;
                sum += right;
            }
        }
        return res;
    }
};
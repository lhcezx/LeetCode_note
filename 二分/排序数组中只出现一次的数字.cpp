//  只出现一次的数字的左右两边，各有偶数个数字。左半数组: 若nums[i] = nums[i + 1]则i一定为偶数; 若nums[i] = nums[i - 1]则i一定为奇数，右半数组及我们要找的值的位置结果相反。因此每次只需要判断，如果mid在左半数组，则left = mid + 1, 反之right = mid - 1;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {                                      //  这里判断left == right是为了防止越界  
            int mid = left + (right - left) / 2;
            //  如果mid为奇数, mid ^ 1 = mid - 1; 如果mid为偶数 mid ^ 1 = mid + 1;
            if (nums[mid] == nums[mid ^ 1]) left = mid + 1;         //  这里的条件能够确定mid在左数组中
            else right = mid - 1;                                   //  注意这里的else无法保证mid在右数组中，只能保证mid在右数组中或我们寻找的那个值的位置。也就是说当mid到达我们的要找的位置, 右边界仍然会左移一个下标到左数组中
        }
        //  left == right == mid
        if (left != 0 && left != nums.size() - 1) {                 //  这里是需要判断当left == right的情况，首先要判断left是否在边界因为left^1存在于越界可能，如果不在边界则判断left和right是否在左数组, 如果存在则left右移一个位置, 返回left
            if (nums[left] == nums[left ^ 1]) left = left + 1;
        }
        return nums[left];
    }
};
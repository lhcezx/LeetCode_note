//  双指针，我们在每个索引i和索引对应的数字nums[i]的位置连一条边，形成一个链表。例如1, 4, 3, 2, 3, 5. 我们进行如下连接0->1->4->3->2->3->2->3...
//  相当于用数组模拟链表，问题转化为找到一个带环链表的环的入口，使用快慢指针解决即可


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (slow != fast || (slow == 0 && fast == 0)) {
            slow = nums[slow];              //  slow = slow->next
            fast = nums[nums[fast]];        //  fast = fast->next->next;
        }
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
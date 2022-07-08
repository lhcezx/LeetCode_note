class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;       //  左右双指针
        while (left < right) {
            while (left < right && !isalnum(s[left])) {     // 判断左指针指向的元素是否为字母或者数字，若不是则跳过
                left++;
            }
            while (left < right && !isalnum(s[right])) {    // 判断右指针指向的元素是否为字母或者数字，若不是则跳过
                right--;
            }
            if (tolower(s[left]) == tolower(s[right])) {    // 判断左右指针元素的小写是否相等，数字的话不会tolower将返回原数字
                left++;
                right--;
            } 
            else return false;
        }
        return true;
    }
};
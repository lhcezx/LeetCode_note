//  字典树，将nums[j]前面的每个十进制数nums[i]的30个二进制位保存到字典树中，由高位向低位保存，若该位为0则开辟left, 若为1则开辟right，高位向低位保存的目的是首先要保证高位的1最多而不是低位的1最多。
//  异或运算若结果为1则要求二进制两个位不相同，则判断函数需要判断输入数字的每一位和字典树中的数字的每一位，若当前数字的某位i为1，则我们需要找到字典树中该位为0，也就是left路径，这样1^0 = 1。反之如果当前数字某位i位0，则找右边路径是否存在，若存在则0^1 = 1, 直到最终结果找到字典树中符合标准的数字，并直接根据x * 2 + 余数的公式计算二进制数字的十进制表达式

class TrieNode{
public:
    TrieNode* left = nullptr;           //  左指针代表二进制位为0
    TrieNode* right = nullptr;          //  右指针代表二进制位为1
    static const int high_bit = 30;     //  最高的int类型二进制位数

    void insert(int num) {              //  向字典树中插入一个数字的二进制路径
        TrieNode* cur = this;
        for (int i = high_bit; i >= 0; i--) {
            int bit = (num >> i) & 1;                    //  从最高位开始判断，是否为1
            if (bit == 1) { 
                if (cur->right == nullptr) {
                    cur->right = new TrieNode();         //  如果位数i为1并且右指针没有被开辟路径，那么创建新节点
                }
                cur = cur->right;
            }
            else if (bit == 0) {
                if (cur->left == nullptr) {
                    cur->left = new TrieNode();          //  如果位数i为0并且左指针没有被开辟路径，那么创建新节点
                }
                cur = cur->left;
            }
        }
    }

    int check(int num) {                            //  找到和num构成最大异或运算结果的存在于字典树中的数字并计算异或运算结果，num在这里就是nums[j]
        TrieNode* cur = this;
        int x = 0;
        for (int i = high_bit; i >= 0; i--) {
            if (((num >> i) & 1) == 1) {            //  当num的第i位二进制数字为1时
                if (cur->left != nullptr) {         //  我们希望从字典树中找到该位为0的数字，因为异或运算0 ^ 1 = 1;
                    cur = cur->left;
                    x = x * 2 + 1;                  //  从高位向低位的方式将二进制数字转十进制，异或运算结果为1 
                }
                else {
                    cur = cur->right;
                    x = x * 2 + 0;
                }
            } else {                                //  当num的第i位二进制数字为0时
                if (cur->right != nullptr) {        //  我们希望从字典树中找到该位位1的数字
                    cur = cur->right;
                    x = x * 2 + 1;                  //  异或运算结果为1
                }
                else {
                    cur = cur->left;
                    x = x * 2 + 0;
                }
            }
        }
        return x;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* node = new TrieNode();
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            node->insert(nums[i]);                              //  每次遍历将第i个数字插入到字典树中
            res = max(res, node->check(nums[i + 1]));                 //  每次遍历计算第i + 1也就是j和它所有的前面的数字的最大异或运算和
        }
        return res;
    }
};
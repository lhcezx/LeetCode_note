class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res; 
        int sz = num.size() - 1;
        int carry = 0;          //  用于判断是否进位
        while (sz >= 0 || k > 0) {
            int x = sz < 0 ? 0: num[sz];        //  如果k的位数比num多，则num退到0以后会--到-1，此时应当用0来和k的位数做加法运算
            int y = k > 0? k % 10: 0;           //  如果k的位数比num多，则num退到0以后会--到-1，此时应当用0来和k的位数做加法运算
            res.push_back((x + y + carry) % 10);
            carry = (x + y + carry) / 10;
            sz--;                               //  指针左移
            k /= 10;                            //  k降位
        }
        if (carry != 0) res.push_back(carry);   //  如果最后还有多出来的进位，ex 370 + 780, 3+7+1 = 11, 应当将进位1放进去
        reverse(res.begin(), res.end());
        return res;

    }
};
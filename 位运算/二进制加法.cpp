class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int sz_a = a.length() - 1, sz_b = b.length() - 1;
        int carry = 0;                               //  用于计算进位
        while (sz_a >= 0 || sz_b >= 0) {
            int x = sz_a < 0 ? 0: a[sz_a] - '0';
            int y = sz_b < 0 ? 0: b[sz_b] - '0';
            int sum = x + y + carry;
            res.append(to_string(sum % 2));
            carry = sum / 2;
            sz_a--;
            sz_b--;
        }
        if (carry != 0) res.append(to_string(carry));
        reverse(res.begin(), res.end());
        return res;
    }
};
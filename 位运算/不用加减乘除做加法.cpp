class Solution {
public:
    int add(int a, int b) {
        if (b == 0) {
            return a;
        }
        return add(a ^ b, static_cast<unsigned int>(a & b) << 1); // a^b为异或操作，与二进制中无进位和相同。 a&b与二进制进位和相同
    }
};
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        vector<int> res(n1 + n2, 0);
        string ans = "";
        //  从右往左进行竖式运算
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int pos1 = i + j, pos2 = i + j + 1;         //  乘积的十位保存在i+j的位置, 个位保存在i+j+1的位置
                int sum = mul + res[pos2];                  //  计算乘积和原本保存在个位位置上的数字的加和
                res[pos2] = sum % 10;
                res[pos1] += sum / 10;                      //  如果进位把进位的数放在pos1位置上
            }
        }
        int idx = 0;
        while (idx < n1 + n2 && res[idx] == 0) idx++;       //  排除前导零
        for (;idx < n1 + n2; idx++) {
            ans.push_back(res[idx] + '0');
        }
        return ans.empty() ? "0" : ans;                     //  避免0和某个数相乘结果为0的情况
    }
};
class Solution {
    vector<string> res;
    vector<int> nums;
    int count = 0;
    int n;
public:
    void backtrack(string& s, int start) {
        if (count == 4) {                               //  当找到四个数字时
            if (start == n) {                           //  如果start到n了，那么将这四个数字放入res中，然后return, 否则直接return
                string tmp = "";
                for (auto num: nums) {
                    tmp.append(to_string(num) + ".");
                }   
                tmp.pop_back();
                res.push_back(tmp);
            }
            return;
        }
        if (start == n) return;                         //  start到n了但没找齐四个数字 return
        if (s[start] == '0') {                          //  零的情况需要单独处理
            nums.push_back(0);
            count++;
            backtrack(s, start + 1);
            count--;
            nums.pop_back();
        }     

        for (int end = start; end < start + 3 && end < n; end++) { 
            int num = stoi(s.substr(start, end - start + 1));    
            if (0 < num && num <= 255) {
                nums.push_back(num);
                count++;
                backtrack(s, end + 1);
                count--;
                nums.pop_back();
            }
            else break;                                 //  不需要继续后移end了，因为从start到end得到的num如果大于255，后移end数字只会更大也同样不满足条件; 或者当num == 0时，会出现前导零，需要单独处理，直接break
        }
    }

    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        backtrack(s, 0);
        return res;
    }
};

//  该题目我们的目的是，从0-white_sz中等概率的随机抽取一个数字(对应题目要求的选取任意一个不在黑名单中的整数)，如果选区的数字num在黑名单中，则通过哈希表保存的映射获取其对应的某个白名单数字，达到既能等概率抽取数字，又能保证不抽取到黑名单中的数字

class Solution {
    int white_sz;                           // 我们实际上希望从白名单中等概率的选取一个随机数
    unordered_map<int, int> hash_map;       // 哈希表，用于保存某个黑名单的数字所应该映射到的白名单数字，用于一旦碰到该黑名单数字，直接提取其对应的白名单数字
    
public:
    Solution(int n, vector<int>& blacklist) {
        int black_sz = blacklist.size();
        white_sz = n - black_sz;
        int last = n - 1;
        //  该循环仅仅用于记录出现的黑名单数字
        for (int c: blacklist) {
            hash_map[c]++;          
        }

        for (int c: blacklist) {           //  该循环用于将所有在[0, white_sz) 中的黑名单数字都映射到[white_sz, n) 区间范围内的白名单数字上，已经在区间中的黑名单数字不需要映射，可以变向的思考为[0, white_len)区间内都是白名单数字，[white_len, n) 范围内全部都是黑名单数字
            if (c >= white_sz) continue;                //  如果该数组已经在区间范围中，则不需要映射
            while (hash_map.count(last)) last--;        //  从n-1向white_len寻找存在于白名单中的数字 (即不存在于黑名单中的数字)
            hash_map[c] = last;      
            last--;       
        }
    }
    
    int pick() {
        int num = rand() % white_sz;        //  从0到白名单长度中随机选取一个数字 (该数字有可能存在黑名单中，如果存在则将其映射到白名单)
        if (hash_map.count(num)) {          //  如果在哈希表中找到num元素，说明num在黑名单中，因此我们直接获取其对应的白名单数字(映射)
            return hash_map[num];
        } 
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
//  自定义比较函数

class Solution {
    unordered_map<int, int> hash_map;
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        for (int i = 0; i < arr2.size(); i++) {
            hash_map[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&] (int a, int b) { // []意为自定义匿名函数, &代表可以引用外部变量
            if (hash_map.count(a)) {
                if (hash_map.count(b)) return hash_map[a] < hash_map[b];
                else return true;                           //  如果b没在哈希表中出现，则将其排在出现在哈希表的a的后面
            } else {
                if (hash_map.count(b)) return false;        //  a没在哈希表出现，将其排在出现在哈希表的b后面
                else return a < b;      
            }});
        return arr1;
    }
};

//  计数排序

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int max = *max_element(arr1.begin(), arr1.end());
        vector<int> freq(max + 1);
        vector<int> res;
        //  记录下每个数字在arr1中出现的次数
        for (auto num: arr1) {
            freq[num]++;            
        }
        //  将出现在arr2中的数字按照顺序和其出现的次数放入数组中
        for (auto num: arr2) {
            if (freq[num] != 0) {
                for (int i = 0; i < freq[num]; i++) {       
                    res.push_back(num);
                }
                freq[num] = 0;
            }
        }
        //  将未出现在arr2中的数字按照升序放入数组
        for (int i = 0; i <= max; i++) {
            for (int j = 0; j < freq[i]; j++) {
                res.push_back(i);
            }
        }
        return res;
    }
};
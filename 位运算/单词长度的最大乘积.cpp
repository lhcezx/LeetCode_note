class Solution {
public:
    int maxProduct(vector<string>& words) {
        int max_len = 0;
        vector<int> bitmasks(words.size());             //  用于保存每一个字符串的bitmasks
        unordered_map<int, int> hash_map;               //  多个字符串可能是同一个Bitemask, ex: eg, eegg, eeegggg. 因此我们只需要记录同一个bitemask中对应的最大的字符串长度
        for(int i = 0; i < words.size(); i++) {         //  遍历每一个字符串
            int bitmask = 0;
            for (auto c: words[i]) bitmask |= (1 << (c - 'a'));      // 遍历字符串中每一个字符
            bitmasks[i] = bitmask;                                   // 将每一个字符串的bitmask放到bitmasks中
            if (hash_map.find(bitmask) == hash_map.end()) hash_map[bitmask] = words[i].length();    //  判断哈希表是否有该bitmask对应的字符串长度，若没有则加入
            else hash_map[bitmask] = max(int(words[i].length()), hash_map[bitmask]);                //  若有，则取字符串较长的保存起来
        }

        for (auto i: hash_map) {            
            for (auto j: hash_map) {
                if ((i.first & j.first) == 0) max_len = max(max_len, (i.second * j.second));   //  遍历每一个bitmask，如果bitmask不同说明不包含同样的字符，
            }
        }
        return max_len;
    }
};
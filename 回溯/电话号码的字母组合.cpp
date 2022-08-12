class Solution {
    unordered_map<char, vector<char>> hash_map;
    vector<string> res;
public:
    void backtrack(string& digits, int i, string& onPath) {
        int n = digits.size();
        if (i >= n) {
            res.push_back(onPath);
            return;
        }
        for (auto c: hash_map[digits[i]]) {
            onPath.push_back(c);
            backtrack(digits, i + 1, onPath);
            onPath.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) { 
        if (digits.empty()) return res;
        string onPath = "";
        hash_map['2'] = {'a', 'b', 'c'};
        hash_map['3'] = {'d', 'e', 'f'};
        hash_map['4'] = {'g', 'h', 'i'};
        hash_map['5'] = {'j', 'k', 'l'};
        hash_map['6'] = {'m', 'n', 'o'};
        hash_map['7'] = {'p', 'q', 'r', 's'};
        hash_map['8'] = {'t', 'u', 'v'};
        hash_map['9'] = {'w', 'x', 'y', 'z'};
        backtrack(digits, 0, onPath);
        return res;
    }
};
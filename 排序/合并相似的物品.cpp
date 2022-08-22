class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> res;
        vector<vector<int>> ans;
        int n1 = items1.size(), n2 = items2.size();
        for (auto item: items1) {
            int value = item[0];
            int weight = item[1];
            res[value] += weight;
        }
        for (auto item: items2) {
            int value = item[0];
            int weight = item[1];
            res[value] += weight;
        }
        for (auto a: res) {
            ans.emplace_back(vector<int> {a.first, a.second});
        }
        return ans;
    }
};
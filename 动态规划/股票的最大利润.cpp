class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = 1e9, res = 0;
        for (auto price: prices) {
            res = max(res, price - min_price);
            min_price = min(price, min_price);
        }
        return res;
    }
};
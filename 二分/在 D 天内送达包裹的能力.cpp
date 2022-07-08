class Solution {
public:
    int daysCounter(vector<int>& weights, int x) {
        int days = 0;
        for (int i = 0; i < weights.size();) {
            int cap = x;        //  船能承载的最大重量
            while (i < weights.size()) {
                if (cap < weights[i]) break;            //  如果第i件货物加上去后会超出船的载重，因此停止加货
                else {
                    cap -= weights[i];                  
                    i++;
                }
            }
            days++;
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for (int weight: weights) {
            left = max(left, weight);       //  最小的载货量为所有货物中的最大值，这样能保证每一件货物都能运走
            right += weight;                //  最大的载货量为所有货物之和，代表一次就能运走
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (daysCounter(weights, mid) > days) left = mid + 1;
            else if (daysCounter(weights, mid) < days) right = mid - 1;
            else if (daysCounter(weights, mid) == days) right = mid - 1;
        }
        return left;
    }
};
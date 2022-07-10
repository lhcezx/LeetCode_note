class Solution {
    vector<int> piles;
public:
    int timeconsum(int s) {
        int total_time = 0;
        for (auto pile: piles) {
            total_time += pile / s;
            if (pile % s > 0) total_time++;
        }
        return total_time;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        this->piles = piles;
        int left = 1, right = 1e9;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (timeconsum(mid) <= h) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};
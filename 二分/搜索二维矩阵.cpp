class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = rows - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] > target) {
                right = mid - 1;
            } else if (matrix[mid][0] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }

        int row = max(0, right);
        left = 0, right = cols - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[row][mid] > target) {
                right = mid - 1;
            } else if (matrix[row][mid] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
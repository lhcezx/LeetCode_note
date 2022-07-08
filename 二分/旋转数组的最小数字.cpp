class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1, mid;
        while (left < right){
            mid = (left + right) / 2;
            if (numbers[mid] < numbers[right]){
                right = mid;
            } else if (numbers[mid] > numbers[right]){
                left = mid + 1;
            } else {
                right -= 1;
            }
            
        }
        return numbers[right];
    }
};

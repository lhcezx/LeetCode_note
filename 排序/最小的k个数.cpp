class Solution {
public:
    int GetMid(vector<int>& arr, int k, int low, int up) {
        int tmp = arr[low];
        while (low < up) {
            while (low < up && arr[up] >= tmp) up--;
            arr[low] = arr[up];
            while (low < up && arr[low] <= tmp) low++;
            arr[up] = arr[low]; 
        }
        arr[low] = tmp;
        return low;
    }

    void QuickSort(vector<int>& arr, int k, int low, int up) {
        if (low >= up) return;
        int mid = GetMid(arr, k, low, up);
        if (mid > k) QuickSort(arr, k, low, mid - 1);
        if (mid < k) QuickSort(arr, k, mid + 1, up);
        if (mid == k) return;
    }
    
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> res;
        QuickSort(arr, k, 0, arr.size() - 1);
        for (int i = 0; i < k; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};
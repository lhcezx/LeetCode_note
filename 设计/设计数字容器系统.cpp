class NumberContainers {
    unordered_map<int, int> idx_num;
    unordered_map<int, set<int>> num_idx;
public:
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if (!idx_num.count(index)) {
            idx_num[index] = number;
            num_idx[number].insert(index);
        } else {
            int num = idx_num[index];
            idx_num[index] = number;
            num_idx[num].erase(index);
            num_idx[number].insert(index);
        }
    }
    
    int find(int number) {
        if (!num_idx.count(number)) return -1;
        return num_idx[number].empty()?-1: *num_idx[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
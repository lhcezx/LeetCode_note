class MyCalendar {
    set<pair<int, int>> s;                          //  pair.first代表start, pair.second代表end
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        //  二分查找我们要添加的时间段[start, end) 中，end后面的第一个预定时间段。
        auto it = s.lower_bound({end, 0});          
        if (it == s.begin() || (--it)->second <= start) {           //  如果后一个时间段为初始时间段，则保证可以插入; 或者后一个时间段的前一个时间段的end在我们要插入的start前面，则也可以插入
            s.emplace(start, end);
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
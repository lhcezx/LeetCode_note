//  有序集合set中记录每个学生的位置，有序的用处是后面遍历每两个学生时是按照索引由小到大遍历，当距离相同时我们选择较小的索引
//  *students.begin() - 0 和 n - 1 - *students.rbegin()为边界条件，分别对应第一个位置到第一个学生的距离和最后一个位置到最后一个学生的距离，学生之间的距离会在for循环中单独记录
class ExamRoom {
    set<int> students;
    int n;
public:
    ExamRoom(int n) {
        this->n = n;
    }
    
    int seat() {
        int pos = 0;
        int prev = -1;
        if (!students.empty()) {
            int max_d = *students.begin();              //  计算第一个学生到教室起始位置的距离 *room.begin() - 0;
            for (auto student: students) {              //  用prev记录前一个学生位置，计算每两个学生之间的距离的一半，找到最大的那个
                if (prev != -1) {
                    int dist = (student - prev) / 2;
                    if (dist > max_d) {                 //  注意这里是大于号，因为当距离相等时我们选择索引靠前的区间，因此是大于
                        max_d = dist;
                        pos = prev + max_d;             //  将位置更新为从prev起到下一个位置的一半
                    }
                }
                prev = student;
            }
            if (n - 1 - *students.rbegin() > max_d) pos = n - 1;        //  计算最后一个学生到教室终点的位置
        }
        students.insert(pos);
        return pos;
    }
    
    void leave(int p) {
        students.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
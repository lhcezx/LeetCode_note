/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> stk;      // 第一个指针是指向某个nestedList的某个元素的指针，第二个指针是该nestedList的尾部指针
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk.emplace(nestedList.begin(), nestedList.end());                    //  两个指针，first是nestedList中从头移动到尾的指针，second是nestedList的尾部指针，用于判断first是否移动到了尾部
    }
    
    int next() {
        return stk.top().first++->getInteger();     //  由于在next前一定会调用hasNext, 因此可以保证栈顶元素pair中的first指针一定指向int元素，因此直接返回栈顶元素的移动指针指向的int元素的值
    }
    
    bool hasNext() {
        while (!stk.empty()) {
            auto &a = stk.top();                    //  这里必须要引用，因为后面我们需要对a的first指针后移，如果不引用的话相当于拷贝了一个栈顶元素，但实际的栈顶元素first指针不会右移，陷入死循环
            if (a.first == a.second) {
                stk.pop();   //  如果栈顶元素的pair元素的first指针到达尾指针，那么说明已经遍历完毕栈顶元素对应的 list 
                continue;
            }                                                                   
            //  如果移动指针不为尾指针的情况下
            if (a.first->isInteger()) return true;                                          //  如果栈顶元素的移动指针指向的是int类型变量，则返回true
            auto &lst = a.first++->getList();                                                //  如果栈顶元素的移动指针指向的是一个nestedList，那么将该list的头节点和尾节点压入栈，注意要将该指针同时向后移动！！
            stk.emplace(lst.begin(), lst.end());                                            //  那么将这个list的头指针和尾指针作为pair压入栈内
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
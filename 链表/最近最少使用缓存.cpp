class LRUCache {
public:
    //  定义双向链表数据结构
    struct DListNode{
        int key, value;
        DListNode *prev, *next;
        DListNode(): key(0), value(0), prev(nullptr), next(nullptr) {};
        DListNode(int _key, int _value): key(_key), value(_value) {};
    };

    unordered_map<int, DListNode*> hash_map;            //  通过key找到对应得DListNode
    DListNode *dummy_head, *dummy_tail;                 //  虚拟头节点，尾节点
    int size;

    LRUCache(int capacity) {
        size = capacity;
        dummy_head = new DListNode();
        dummy_tail = new DListNode();
        dummy_head->next = dummy_tail;
        dummy_tail->prev = dummy_head;
    }

    void remove(DListNode* node) {
        node->prev->next = node->next;      
        node->next->prev = node->prev;
    }

    void addhead(DListNode* node) {
        node->next = dummy_head->next;      
        node->next->prev = node;
        node->prev = dummy_head;
        dummy_head->next = node;
    }
    
    int get(int key) {
        if (!hash_map.count(key)) return -1;
        DListNode* node = hash_map[key];
        remove(node);                       //  将访问的节点从原节点位置删除
        addhead(node);                      //  将访问的节点接到头结点位置
        return node->value;
    }
    
    void put(int key, int value) {
        if (hash_map.count(key)) {                                      //  如果已经存在，则修改原始数据，将其从链表中删除并移动到头节点
            DListNode* node = hash_map[key];
            node->value = value;
            remove(node);
            addhead(node);                                         
        } else {           
            DListNode* node = new DListNode(key, value);                //  如果不存在于链表中，则需要先判断插入会不会导致超出capacity
            if (hash_map.size() >= size) {                              //  如果超出size，则删除尾节点
                DListNode* tail = dummy_tail->prev;
                remove(tail);
                hash_map.erase(tail->key);
                delete tail;                                            //  删除该指针，防止内存泄露
            } 
            hash_map[key] = node;
            addhead(node);
        }
        
    }
};




//  链表的插入和删除的时间复杂度为O(1), 但是由于没有索引机制，查找速度很慢; 哈希表的查找速度为O(1), 但是插入和删除的速度很慢。因此我们将哈希表和双向链表结合，实现查找和插入的时间复杂度均为O(1)
//  使用双向链表的原因是，我们通过链表保存时序信息，最近使用的元素放在链表头部，最后使用的元素放在尾部，每次插入和删除操作，需要知道前驱节点和后驱节点，因此需要双向链表。
//  节点中不但需要保存val的信息，还需要保存key的信息，因为当我们删除最后一个节点时，我们同时需要把哈希表中对应的键值对也删除，而哈希表中的键我们需要从节点中保存的键获取，否则我们无法删除哈希表中的键值对

class DListNode {                   
public:
    int key, val;
    DListNode* next = nullptr;
    DListNode* prev = nullptr;
    DListNode(int _key, int _val): key(_key), val(_val) {}
};

class LRUCache {
    unordered_map<int, DListNode*> hash_map;
    DListNode* dummy_head;
    DListNode* dummy_tail;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        dummy_head = new DListNode(-1, -1);
        dummy_tail = new DListNode(-1, -1);
        dummy_head->next = dummy_tail;
        dummy_tail->prev = dummy_head; 
    }

    DListNode* removeNode(int key) {
        DListNode* node = hash_map[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;
        return node;
    }

    void removeLast() {
        DListNode* tail = dummy_tail->prev;
        hash_map.erase(tail->key);              //  同时要将哈希表中对应的键值对删除
        tail->prev->next = dummy_tail;
        dummy_tail->prev = tail->prev;
        delete tail;
    }

    void addToHead(DListNode* node) {
        node->next = dummy_head->next;
        node->prev = dummy_head;
        node->next->prev = node;
        dummy_head->next = node;
    }
    
    int get(int key) {
        if (!hash_map.count(key)) return -1;
        DListNode* node = removeNode(key);
        addToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (hash_map.count(key)) {                          //  如果这个键值对已经存在，则直接在原有的基础上修改双向链表的节点的值, 并将访问的节点放到链表首位
            DListNode* node = removeNode(key);
            node->val = value;
            addToHead(node);
            return;
        }
        if (hash_map.size() >= capacity) {                  //  如果键值对不存在，并且达到容量上限，则需要删除未使用过时间最久的节点也就是最后一个节点       
            removeLast();
        }
        DListNode* node = new DListNode(key, value);
        hash_map[key] = node;
        addToHead(node);                                    //  将新添加的node放到哈希表的键值对中
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
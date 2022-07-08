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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
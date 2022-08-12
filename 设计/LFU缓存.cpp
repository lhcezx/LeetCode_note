//  保存key的原因是，当我们要删除某个节点的时候，需要同时在key_table中删除对应的哈希键值对
//  保存freq的原因是，当我们访问或者修改某个key时，它的freq++，我们需要将其从原来的freq的链表中删除并放到freq+1的链表的表头
struct Node {
    int key;
    int val;    
    int freq;
    Node(int _key, int _val, int _freq): key(_key), val(_val), freq(_freq) {}
};

class LFUCache {
    unordered_map<int, list<Node>::iterator> key_table;           //  每个键key保存着对应的链表节点的地址，注意这里必须保存地址，否则对链表节点的修改需要手动更新哈希表
    unordered_map<int, list<Node>> freq_table;                    //  每个freq对应一个链表，表头是最新的元素，表尾是最旧的元素
    int capacity;
    int min_freq = 0;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        key_table.clear();
        freq_table.clear();
    }
    
    //  用于超出容量时，删除最小使用频率的最不常用的节点，也就是其链表的尾节点
    void removeLast(int freq) {
        Node last = freq_table[freq].back();        //  找到这个freq对应的链表list_node中的表尾元素
        key_table.erase(last.key);                  //  将其从key_table中删除
        freq_table[freq].pop_back();                //  将其从list_node删除
        if (freq_table[freq].size() == 0) {         //  如果这条链表为空了，则直接删除这个键表对，并更新min_freq
            freq_table.erase(freq);
            if (min_freq == freq) min_freq++;
        }
    }

    //  用于当调用get或put当键存在时，将其从freq的链表中删除然后放到freq + 1的链表表头, 此函数中除了freq对应的链表节点全部被删除的情况外，min_freq不需要更新，因为freq只增加不减少
    void moveToHead(int key) {                     
        //  首先将节点从freq的链表中删除
        list<Node>::iterator iter = key_table[key];
        int val = iter->val;
        int freq = iter->freq;
        freq_table[freq].erase(iter);
        if (freq_table[freq].size() == 0) {         //  如果这条链表为空了，则直接删除这个键表对，并更新min_freq
            freq_table.erase(freq);
            if (min_freq == freq) min_freq++;
        }
        //  然后将该节点加入到freq + 1的链表头部
        //  由于freq_table[freq].erase(iter)会直接将iter指针从链表中删除，并且DELETE！！因此iter不能再继续使用，需要创建一个新的节点放到freq+1链表表头，并更新key_table中的key对应的节点地址
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();
    }

    int get(int key) {
        if (!key_table.count(key) || capacity == 0) return -1;
        moveToHead(key);
        return key_table[key]->val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        //  如果这个键值对存在，则直接修改并更新freq
        if (key_table.count(key)) {
            auto iter = key_table[key];
            iter->val = value;
            moveToHead(key);
            return;
        }

        //  如果键不存在
        if (key_table.size() == capacity) {
            removeLast(min_freq);
        }
        freq_table[1].push_front(Node(key, value, 1));
        key_table[key] = freq_table[1].begin();
        min_freq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
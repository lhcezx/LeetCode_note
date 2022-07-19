int timestamp = 0;                  //  时间戳

//  推文类: 内容，传入时间，下一条推文
class Tweet {
public:
    int tw_id;
    int time;
    Tweet* next;
    Tweet(int _tw_id, int _time): tw_id(_tw_id), time(_time), next(nullptr) {}
};

//  用户类: 用户id, 关注列表, 发表最新推文
class User {
public:
    int id;
    Tweet* head;
    unordered_set<int> followed;        //  哈希集合，保证关注的人不重复
    User(int _id): id(_id), head(nullptr) {}

    void follow(int id) {
        if (id == this->id) return;
        followed.insert(id);
    }

    void unfollow(int id) {
        if (id == this->id) return;                               //  不可以取关自己
        followed.erase(id);
    }

    void post(int tw_id) {
        Tweet* tweet = new Tweet(tw_id, timestamp);
        timestamp++;
        tweet->next = head;             //  将最新的推文接到头节点前面
        head = tweet;                   //  令其等于头节点
    }       
};


class Twitter {                 
public:
    unordered_map<int, User*> hash_map;      //  通过用户id找到对应的用户实例
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        if (!hash_map.count(userId)) hash_map[userId] = new User(userId);
        hash_map[userId]->post(tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if (!hash_map.count(userId)) return res;
        // 将时间戳最大的排在最后，也就是最新的推文
        unordered_set<int> followed = hash_map[userId]->followed;                           //  找到用户关注的所有关注者
        auto cmp = [&] (const Tweet* a, const Tweet* b) {return a->time < b->time;};
        priority_queue<Tweet*, vector<Tweet*>, decltype(cmp)> pq(cmp);

        if (hash_map[userId]->head != nullptr) pq.push(hash_map[userId]->head);             //  把自己的推文也放到优先队列中
        for (int followee: followed) {
            if (!hash_map.count(followee)) continue;
            if (hash_map[followee]->head != nullptr) pq.push(hash_map[followee]->head);     //  将每个用户的推文链表放入堆中，堆顶是最新的推文
        }
        while (!pq.empty()) {
            if (res.size() == 10) break;
            Tweet* tw = pq.top();
            pq.pop();
            res.push_back(tw->tw_id);
            if (tw->next != nullptr) pq.push(tw->next);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (!hash_map.count(followerId)) hash_map[followerId] = new User(followerId);
        if (!hash_map.count(followeeId)) hash_map[followeeId] = new User(followeeId);
        hash_map[followerId]->follow(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (!hash_map.count(followerId)) return;

        hash_map[followerId]->unfollow(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
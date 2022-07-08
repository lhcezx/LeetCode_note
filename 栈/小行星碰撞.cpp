class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        //  注意这里的i++放在if判断中，为的是每次循环不一定让i++, 而是根据栈顶元素和当前元素i判断是否要进入下一循环，并且每次都需要判断 if (s.empty() || s.top() < 0 || tmp > 0)条件是否满足
        for (int i = 0; i < asteroids.size();) {
            int tmp = asteroids[i];
            if (s.empty() || s.top() < 0 || tmp > 0) {
                s.push(tmp);                                        //  如果栈为空，或者栈顶元素向左移动(入栈元素无论向左还是向右都不会碰撞)，或者入栈元素向右移动(无论前面的行星向左还是向右都不会碰撞) 
                i++;
            }   
            else {                                                  //  栈顶元素为正向右，入站元素为负向左，会发生碰撞
                if (abs(s.top()) < abs(tmp)) s.pop();               //  如果栈顶元素比入站元素小，则发生碰撞并且出栈(撞毁)
                else if (abs(s.top()) == abs(tmp)) {                //  如果栈顶元素和入站元素相等，则两两撞毁，进入下一循环。
                    s.pop();
                    i++;
                }
                else i++;
            }
        }
        vector<int> res(s.size());
        for (int i = s.size() - 1; i >= 0 ; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};
class Solution {
public:
    string removeDuplicateLetters(string s) {
        //  用于保存字符串的中的每一个字符，用栈的原因是我们每次可以比较将要入栈的元素和当前栈顶元素从而保证最小字典序，进行大小比对使得栈内元素维持从小到大的顺序
        stack<char> s1;                         
        vector<bool> instack(128);              //  用于判断字符是否重复出现，也就是是否已经存在栈中
        vector<char> count(128);                //  用于记录字符串中的字符出现的次数
        string res = "";

        for (char c: s) {                       //  记录整个字符串中的每个字符出现的次数分别是多少
            count[c]++;
        }
        
        for (char c: s) {
            count[c]--;                                          //  遍历每个字符的时候，将其出现次数--，当count[c] == 0的时候代表该元素在后面不会再出现了，因为前面出现的次数等于整个字符串中它出现的次数
            if (instack[c] == true) continue;                    //  跳过重复的字符
            while (!s1.empty() && c < s1.top()  ) {              //  当我们发现后面的字符比前面的小的时候，为保证字典序最小，应当把小的字符放在前面，因此将前面的字符pop
                if (count[s1.top()] == 0) break;                 //  若栈顶元素在后面不会再出现了，则停止pop防止误删   
                instack[s1.top()] = 0;                           //  pop出去的元素应当将其恢复0为表示未出现过
                s1.pop();   
            }
            s1.push(c);
            instack[c] = 1;
        }

        while (!s1.empty()) {
            res.push_back(s1.top());
            s1.pop();
        }
        reverse(res.begin(), res.end());                          // 由于入栈出栈后会颠倒字符顺序，因此需要reverse
        return res;
    }
};
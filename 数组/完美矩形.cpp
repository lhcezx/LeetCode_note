//  本题的思路，从矩形的顶点和面积出发, 若最终形成的矩形为完美矩形，那么需要满足几个条件: 1. 完美矩形的面积和各个小矩阵的面积和相等 2. 矩形只有四个顶点 3. 这四个顶点分别对应左上，右上，左下，右下
//  有一个要点，如果一个角点出现的次数为奇数，那么这个角点被看作是角点，若出现的次数为偶数，则不被看作为角点
typedef pair<int, int> pt;
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pt> isCoin;
        int X1 = INT_MAX, Y1 = INT_MAX;             //  完美矩形左上角顶点
        int X2 = INT_MIN, Y2 = INT_MIN;             //  完美矩形右下角顶点
        long area = 0;
        for (auto rectangle: rectangles) {  
            int x1 = rectangle[0], y1 = rectangle[1], x2 = rectangle[2], y2 = rectangle[3];         
            X1 = min(X1, x1), Y1 = min(Y1, y1), X2 = max(X2, x2), Y2 = max(Y2, y2);                 //  完美矩形左上角点是(x, y)最小的点，右下角是(x, y)最大的点
            area += (long)(x2 - x1) * (y2 - y1);
            pt lu = {x1, y1}, ru = {x2, y1}, ld = {x1, y2}, rd = {x2, y2};                          //  小矩形的四个角点
            for (auto p: {lu, ru, ld, rd}) {
                if (isCoin.count(p)) isCoin.erase(p);          //  如果p出现在哈希集合中，则将其删除，否则将其加入集合。这样做的目的是出现次数为奇数的角点会保存在集合内，偶数次数的角点不会出现在集合
                else isCoin.insert(p);
            }
        }
        long AREA = (long)(X2 - X1) * (Y2 - Y1);
        if (isCoin.size() != 4) return false;               //  判断角点数量是否为4
        if (area != AREA) return false;                     //  判断小矩形面积和是否等于完美矩形面积
        if (!isCoin.count({X1, Y1})) return false;          //  验证哈希集合中保存的每个角点是否和记录完美矩形X1, X2, Y1, Y2相同
        if (!isCoin.count({X1, Y2})) return false;
        if (!isCoin.count({X2, Y1})) return false;
        if (!isCoin.count({X1, Y2})) return false;
        return true;
    }
};
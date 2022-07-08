class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int tmp = 1;
        vector<int> b(a.size(), 1) ;
        for(int i = 1; i < a.size(); i++) {
            b[i] = b[i-1] * a[i-1];             // 左下的三角形处理完毕, b[0] = 1; b[1] = 1*a[0] = a[0]; b[2] = b[1]*a[1] = a[0]*a[1]; b[3] = b[2]*a[2] = a[0]*a[1]*a[2];....... 直到最后b[n] = a[0]*a[1]*....a[n-1]，因此b[n]已经累乘完毕，我们后面要从后往前累乘，从b[n-1]开始算
        }
        for(int i = (a.size() - 1) - 1; i >= 0; i--) {        // a.size() - 1为a和b最后一个元素的索引, 再次-1代表让B的索引从倒数第二个开始
            tmp *= a[i+1];                                   // a[n]; a[n]*a[n-1]; a[n]*a[n-1]*a[n-2]; a[n]*....a[1]; 用tmp作为临时变量来储存右上三角的每一行中b[i]缺乘的那部分，然后和b[i]乘起来获得最终的b[i]
            b[i] *= tmp;
        }
        return b;
    }
};
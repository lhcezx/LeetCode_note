class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL){
            return false;
        }
        if (recur(A, B)){
            return true;
        }
        if (isSubStructure(A->left, B)){
            return true;
        }
        if (isSubStructure(A->right, B)){
            return true;
        }
        return false;
    }

    bool recur(TreeNode* A, TreeNode* B){
        if (B == NULL) return true;
        if (A == NULL || A->val != B->val) return false;
        return recur(A->left, B->left) && recur(A->right, B->right);
    }
};
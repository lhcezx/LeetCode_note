/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front == nullptr) res.append("#,");
            else {
                res.append(to_string(front->val) + ",");
                q.push(front->left);
                q.push(front->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        vector<TreeNode*> vec;
        while (i < data.size()) {
            string tmp = "";
            while (data[i] != ',') {
                tmp.push_back(data[i++]);
            }
            if (tmp != "#") vec.push_back(new TreeNode(stoi(tmp)));
            else vec.push_back(nullptr);
            i++;
        }
        int j = 1;
        for (int i = 0; i < vec.size(); i++) {
            if (j < vec.size() && vec[i] != nullptr) vec[i]->left = vec[j++];
            if (j < vec.size() && vec[i] != nullptr) vec[i]->right = vec[j++];
        }
        return vec[0];

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
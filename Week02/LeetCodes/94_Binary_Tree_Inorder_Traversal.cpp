class Solution {
public:
    enum {Black=0, White};
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};

        stack<pair<TreeNode*, int>> s;
        s.push({root, Black});

        vector<int> res;
        while(s.size()) {
            pair<TreeNode*, int> node = s.top();
            s.pop();
            if (node.second == White) {
                res.push_back(node.first->val);
            } else {
                if (node.first->right) s.push({node.first->right, Black});
                s.push({node.first, White});
                if (node.first->left) s.push({node.first->left, Black});
            }
        }

        return res;
    
    }

};

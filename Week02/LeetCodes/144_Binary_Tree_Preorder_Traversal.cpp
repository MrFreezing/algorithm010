class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> s;
        s.push(root);
        while(s.size()) {
            TreeNode * p = s.top();
            s.pop();
            if (p) res.push_back(p->val);
            if(p->right) s.push(p->right);
            if(p->left) s.push(p->left);
        }

        return res;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    typedef vector<int>::iterator it;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        if ( len == 0 || len != inorder.size()) 
            return nullptr;
        
        return buildNode(preorder.begin(), inorder.begin(), len);
    }

    TreeNode * buildNode(it preOrderPos, it inOrderPos, int len) {
        if (len <= 0 || preOrderPos == inOrderPos) return nullptr;

        //position in inOrder
        it pos = find(inOrderPos, inOrderPos + len, *preOrderPos);
        if (pos == (inOrderPos + len)) return nullptr;

        TreeNode * root = new TreeNode(*preOrderPos);

        //left tree length
        int leftLen = pos - inOrderPos;
        if (leftLen)
            root->left = buildNode(preOrderPos + 1, inOrderPos, leftLen);

        //right tree length
        int rightLen = inOrderPos + len - pos - 1;
        if (rightLen)
            root->right = buildNode(preOrderPos + 1 + leftLen, inOrderPos + leftLen + 1 , rightLen);

        return root;        
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};

        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        vector<int> line;

        while(q.size()) {
            Node * p = q.front();
            q.pop();

            if (p) {
                line.push_back(p->val);
                for (auto cl : p->children) 
                    if (cl) q.push(cl);
            } else {
                res.push_back(line);
                line.clear();
                if (q.size()) q.push(NULL);
            }
        }
        return res;
    }
};

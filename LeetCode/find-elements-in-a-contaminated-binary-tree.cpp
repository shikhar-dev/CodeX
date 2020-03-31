// Problem URL: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree// /
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:

    unordered_map <int,bool> mp;

    FindElements(TreeNode* root) {
        // BFS
        queue<TreeNode *> q;
        root->val = 0;
        q.push(root);
        while (!q.empty()) {
            TreeNode *ptr = q.front();
            q.pop();
            int pval = ptr->val;
            mp[pval] = true;
            if (ptr->left != NULL) {
                ptr->left->val = 2*pval+1;
                q.push(ptr->left);
            }
            if (ptr->right != NULL) {
                ptr->right->val = 2*pval+2;
                q.push(ptr->right);
            }
        }
    }

    bool find(int target) {
        return mp[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
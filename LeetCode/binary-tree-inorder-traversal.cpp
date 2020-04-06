// Problem URL: https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> ans;
        if (root == NULL) return ans;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        st2.push(root);
        while (!st2.empty()) {
            while (st1.top() != st2.top()) {
                ans.push_back(st1.top()->val);
                st1.pop();
            }
            TreeNode* node = st1.top();
            st1.pop();
            st2.pop();
            if (node->right != NULL) {
                st1.push(node->right);
                st2.push(node->right);
            }
            st1.push(node);
            if (node->left != NULL) {
                st1.push(node->left);
                st2.push(node->left);
            }
        }
        while (!st1.empty()) {
            ans.push_back(st1.top()->val);
            st1.pop();
        }
        return ans;
    }
};
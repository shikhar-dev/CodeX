// Problem URL: https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
private:
    int dfs(TreeNode* node) {
        if (node == NULL) return 0;
        return max(dfs(node->left), dfs(node->right)) + 1;
    }
public:
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};
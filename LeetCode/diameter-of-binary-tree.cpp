// Problem URL: https://leetcode.com/problems/diameter-of-binary-tree/
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
    int ans = 0;
    int dfs(TreeNode* node) {
        if (node == NULL) return 0;
        int ll,rl;
        ll = dfs(node->left);
        rl = dfs(node->right);
        ans = max(ll+rl, ans);
        return max(ll,rl) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
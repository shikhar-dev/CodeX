// Problem URL: https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode * node, int numSoFar) {
        int num = numSoFar*10 + node->val;
        int sumL=0, sumR = 0;

        if (node->left == NULL and node->right == NULL) return num;

        if (node->left != NULL) sumL = dfs(node->left, num);
        if (node->right != NULL) sumR = dfs(node->right, num);

        return sumL + sumR;
    }
};
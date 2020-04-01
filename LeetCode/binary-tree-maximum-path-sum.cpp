// Problem URL: https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int ans;
public:
    int maxPathSum(TreeNode* root) {
        // Base value
        ans = root->val;
        dfs(root, 0);
        return ans;
    }

    int dfs(TreeNode * node, int sumSoFar) {
        int sumLCA = node->val + sumSoFar;
        int sA=sumLCA, sB = sumLCA;

        if (node->left != NULL) sA = max(dfs(node->left, sumLCA),sA);
        if (node->right != NULL) sB = max(dfs(node->right, sumLCA),sB);

        ans = max(ans, sA + sB - 2*sumLCA + node->val);

        return max(sA, sB);
    }
};
// Problem URL: https://leetcode.com/problems/flip-equivalent-binary-trees/
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
    int getVal(TreeNode * node) {
        if (node == NULL) return -1;
        else return node->val;
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL and root2 == NULL)    return true;
        else if (root1 == NULL || root2 == NULL) return false;
        if (root1 -> val != root2 -> val) return false;

        if (getVal(root1->left) != getVal(root2->left)) swap(root1->left, root1->right);

        return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
    }
};
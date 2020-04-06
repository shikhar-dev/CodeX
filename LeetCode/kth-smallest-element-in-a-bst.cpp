// Problem URL: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    int cnt=0,ans=0;

    void inorder(TreeNode* node,int k) {
        if (node->left != NULL)
            inorder(node->left,k);
        cnt++;
        if (cnt == k)   ans=node->val;
        if (node->right != NULL)
            inorder(node->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};
// Problem URL: https://leetcode.com/problems/merge-two-binary-trees/
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
    TreeNode* recur(TreeNode* node1, TreeNode* node2) {
        if (node1 == NULL and node2 == NULL) return NULL;
        TreeNode *left1=NULL,*right1=NULL,*left2=NULL,*right2=NULL;
        int val=0;
        if (node1 != NULL) {
            val += node1->val;
            left1 = node1->left;
            right1 = node1->right;
        }
        if (node2 != NULL) {
            val += node2->val;
            left2 = node2->left;
            right2 = node2->right;
        }

        TreeNode* newNode = new TreeNode(val);
        newNode->left = recur(left1,left2);
        newNode->right = recur(right1,right2);
        return newNode;
    }
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return recur(t1,t2);
    }
};
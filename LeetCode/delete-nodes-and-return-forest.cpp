// Problem URL: https://leetcode.com/problems/delete-nodes-and-return-forest/
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
    unordered_map<int, bool> mp;
    vector <TreeNode*> ans;

    void dfs(TreeNode* node, bool makeRoot) {
        if (node == NULL) return;
        if (mp[node->val]) makeRoot = true;
        else if (makeRoot) {
            ans.push_back(node);
            makeRoot = false;
        }

        dfs(node->left,makeRoot);
        dfs(node->right,makeRoot);

        if (node->left != NULL and mp[node->left->val]) node->left = NULL;
        if (node->right != NULL and mp[node->right->val]) node->right = NULL;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto x: to_delete) mp[x]=true;
        dfs(root, true);
        return ans;
    }
};
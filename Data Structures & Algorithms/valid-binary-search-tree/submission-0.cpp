/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {-INT_MAX, INT_MAX}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int lb = it.second.first;
            int rb = it.second.second;

            if(!(lb<node->val && node->val<rb)) return false;

            if(node->left) q.push({node->left, {lb, node->val}});
            if(node->right) q.push({node->right, {node->val, rb}});
        }

        return true;
    }
};

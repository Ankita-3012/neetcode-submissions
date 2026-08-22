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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int cnt =0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int maxval = it.second;
            if(node->val >= maxval){
                cnt++;
            }
            if(node->left) q.push({node->left, max(maxval, node->val)});
            if(node->right) q.push({node->right, max(maxval, node->val)});
        }
        return cnt;
    }
};

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
private:
    int calH(TreeNode* node){
        if(!node) return 0;
        int lh = calH(node->left);
        int rh = calH(node->right);

        return 1+max(lh, rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int lH = calH(root->left);
        int rH = calH(root->right);
        if(abs(lH - rH) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

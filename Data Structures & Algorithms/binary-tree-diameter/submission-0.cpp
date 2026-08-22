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
    int d =0;
    int calH(TreeNode* node){
        if(node == nullptr) return 0;

        int leftH = calH(node->left);
        int rightH = calH(node->right);

        d = max(d, leftH+rightH);

        return 1+max(leftH, rightH);
    }
    int diameterOfBinaryTree(TreeNode* root) {

        calH(root);
        return d;

    }
};

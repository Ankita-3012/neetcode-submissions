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
    int calH(TreeNode* node, int& d){
        if(node == nullptr) return 0;

        int leftH = calH(node->left, d);
        int rightH = calH(node->right, d);

        d = max(d, leftH+rightH);

        return 1+max(leftH, rightH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        calH(root, d);
        return d;

    }
};

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
    string serialize(TreeNode* p){
        if(!p) return "$#";
        return "$"+to_string(p->val)+serialize(p->left)+serialize(p->right);
    }

    vector<int> zArray(string s){
        int n = s.size();
        vector<int> z(n, 0);
        int l=0, r = 0;
        for(int i=1; i<n; i++){
            if(i<=r) z[i] = min(z[i-l], r-i+1);
            while(i+z[i]<n && s[z[i]] == s[i + z[i]]) z[i]++;

            if(i+z[i]-1>r){
                l = i;
                r = i+z[i]-1;
            }
        }
        return z;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string ser_root = serialize(root);
        string ser_subroot= serialize(subRoot);
        string comb = ser_subroot + "|" + ser_root;

        vector<int> z = zArray(comb);

        int len = ser_subroot.size();
        for(int i=1; i<comb.size(); i++){
            if(z[i] == len) return true;
        }

        return false;
    }
};

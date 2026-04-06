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
    int x_level, y_level, xparent, yparent;

    void traverse(TreeNode* root, int x, int y, int parent, int level){
        if(root == NULL) return;

        if(root->val == x){
            x_level = level;
            xparent = parent;
            return;
        }
        if(root->val == y){
            y_level = level;
            yparent = parent;
            return;
        }
        traverse(root->left, x, y, root->val, level+1);
        traverse(root->right, x, y, root->val, level+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y){
            return false;
        }

        traverse(root, x, y, 0, 1);
        
        return(x_level == y_level && xparent != yparent);

    }   
};
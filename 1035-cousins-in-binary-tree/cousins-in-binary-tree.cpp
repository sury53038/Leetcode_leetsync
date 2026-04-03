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
    int xdepth, ydepth, x_parent, y_parent;
    void check(TreeNode* root, int x, int y, int depth, int parent){
        if(root == NULL) return;

        if(root->val == x){
            xdepth = depth;
            x_parent = parent;
            return;
        }

        if(root->val == y){
            ydepth = depth;
            y_parent = parent;
            return;
        }
        check(root->left, x, y, depth+1, root->val);
        check(root->right, x, y, depth+1, root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == y || root->val == x) return false;

        check(root, x, y, 0, -1);

        return (xdepth == ydepth && x_parent != y_parent);
    }
};
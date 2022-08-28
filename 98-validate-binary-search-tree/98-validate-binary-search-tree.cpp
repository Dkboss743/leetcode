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
    bool util(TreeNode *root , long low , long high)
    {
        if(root == NULL){
            return true;
        }
        if((root->val < high) && (root->val > low)){
            return util(root->left,low , root->val) && util(root->right,root->val,high);
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
      return util(root, LONG_MIN, LONG_MAX);
    }
    
};
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
   TreeNode*prev=NULL;
 void solve(TreeNode* root)
{
    if(!root)
        return;
        // -------------------------------------------------------------------approach1;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;

}
    void flatten(TreeNode* root) {
        // solve function is approach1
        solve(root);
        return;
        // --------------------------------------approach2
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->left!=NULL)
            {
              TreeNode*  prev=curr->left;
                while(prev->right)
                {
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
           
            }
            curr=curr->right;
        }
    }
};
class Solution {
public:
    bool check(TreeNode* node1,TreeNode* node2)
    {
        if(!node1||!node2)
        {
            return node1==node2;
        }
        if(node1->val!=node2->val)
        {
            return false;
        }
       if(!check(node1->left,node2->right))
       return false;
        if(!check(node1->right,node2->left))
        return false;
        return true;

    }
    bool isSymmetric(TreeNode* root) {
        if(!root->left||!root->right)
        {
         return(root->left==root->right);   
        }
        return check(root->left,root->right);
    }
};
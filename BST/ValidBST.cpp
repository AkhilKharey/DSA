class Solution {
public:
    bool isValid(TreeNode* node,long long int minval,long long int maxval)
    {
        if(!node)
        return true;
        if(node->val <=minval || node->val >=maxval)
        return false;
        return (isValid(node->left,minval,node->val) && isValid(node->right,node->val,maxval));
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root,pow(-2,31)-1,pow(2,31)+1);
    }
};
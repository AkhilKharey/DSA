class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ansnode=NULL;
        TreeNode* node=root;
        while(node)
        {
            if(node->val > val )
            node=node->left;
            else if(node->val < val)
            node=node->right;
            else if(node->val ==val)
            {
                ansnode=node;
                break;
            }
        }
        return node;

    }
};
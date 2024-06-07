class Solution {
public:
    TreeNode* helper(TreeNode* node)
    {
        if(!node->left)
        return node->right;
        if(!node->right)
        return node->left;
        TreeNode* rightguy=node->right;
        TreeNode* lastRight=findlastRight(node->left);
        lastRight->right=rightguy;
        return node->left;
    }
    TreeNode* findlastRight(TreeNode* node)
    {
        while(node->right)
        node=node->right;
        
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
        return NULL;
        if(root->val==key)
        return helper(root);
        TreeNode* node=root;
        while(node)
        {
            if(key<node->val)
            {
              if(node->left!=NULL && node->left->val==key)
              {
                  node->left=helper(node->left);
                  break;
              }
              else
              {
                  node=node->left;
              }
            }
            else if(key>node->val)
            {
                if(node->right!=NULL && node->right->val==key)
                {
                    node->right=helper(node->right);
                    break;
                }
                else
                {
                    node=node->right;
                }
            }
        }
        return root;

    }
};
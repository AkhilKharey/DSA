class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=root;
        TreeNode* newnode;
        if(!root)
        {
            newnode=new TreeNode(val);
            return newnode;
        }
        TreeNode* prev=NULL;
        while(node)
        {
           if(val > node->val)
           {
                prev=node;
                node=node->right;
                if(!node)
                {
                   newnode=new TreeNode(val);
                  prev->right=newnode;
                  newnode->right=NULL;
                  newnode->left=NULL;
                  break;
                }
               
           }
           else if(val<node->val)
           {
               prev=node;
               node=node->left;
               if(!node)
               {
                    newnode=new TreeNode(val);
                   prev->left=newnode;
                  newnode->right=NULL;
                 newnode->left=NULL;
                   break;
               }
       
           }

        }
        return root;
    }
};
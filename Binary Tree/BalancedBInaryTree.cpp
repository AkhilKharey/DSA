// -----------------------------------------------------------Approach1
// naive
class Solution {
public:  
    int findHeight(TreeNode* node)
    {
        if(node==NULL)
        return 0;
        int lh=findHeight(node->left);
        int rh=findHeight(node->right);
        return 1+max(lh,rh);
        
    }
  
    bool check(TreeNode* node)
    {
        if(node==NULL)
        return true;
        int lh=findHeight(node->left);
        int rh=findHeight(node->right);

        if(abs(lh-rh)>1)
        return false;

        bool left=check(node->left);
        bool right=check(node->right);
        if(!left||!right)
        return false;
        return true;
    }
    bool isBalanced(TreeNode* root) {
       return check(root);

    }
};

// --------------------------------------------------------------APPROACH2 O(N)
class Solution {
public: 
    int findHeight(TreeNode* node)
    {
        if(node==NULL)
        return 0;
        int lh=findHeight(node->left);
        int rh=findHeight(node->right);
        if(lh==-1||rh==-1)
        return -1;
        if(abs(lh-rh)>1)
        return -1;
        else
        return 1+max(lh,rh);
    }
   ]
    bool isBalanced(TreeNode* root) {
        if(findHeight(root)==-1)
        return false;
        return true;
    }
};
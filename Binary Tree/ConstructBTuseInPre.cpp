class Solution {
public:
   TreeNode* inorderPreorder(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,unordered_map<int,int>&imp)
    {
        if(prestart>preend||instart>inend)
        return NULL;

        TreeNode* root=new TreeNode(preorder[prestart]);
       int inroot=imp[root->val];
        int numleft=inroot-instart;
    root->left=inorderPreorder(preorder,prestart+1,prestart+numleft,inorder,instart,inroot-1,imp);
    root->right=inorderPreorder(preorder,prestart+numleft+1,preend,inorder,inroot+1,inend,imp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
   unordered_map <int,int>imap;
    for(int i=0;i<inorder.size();i++)
    imap[inorder[i]]=i;
    TreeNode* root=inorderPreorder(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,imap);
    return root;
    }
};
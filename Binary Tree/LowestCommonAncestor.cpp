// ----------------------------------------APPROACH1
class Solution {
public:
    bool nodepath(TreeNode* node,vector<TreeNode*>&ans,TreeNode* x)
    {
        if(node==NULL)
        return false;
        ans.push_back(node);
        if(node==x)
        return true;
        if(nodepath(node->left,ans,x)||nodepath(node->right,ans,x))
        return true;
        ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>ans1;
        vector<TreeNode*>ans2;
        nodepath(root,ans1,p);
        nodepath(root,ans2,q);
        TreeNode* ansnode;
       int size=min(ans1.size(),ans2.size());
       for(int i=0;i<size;i++)
       {
           if(ans1[i]==ans2[i]) 
           ansnode=ans1[i];
       }
       return ansnode;
    }
};
// --------------------------------------------------------------------APPROACH2
class Solution {
public:
    TreeNode* solve(TreeNode* node,TreeNode* p,TreeNode*q)
    {
        // base case
       if(node==NULL||node==p||node==q)
       return node;

       TreeNode* leftnode=solve(node->left,p,q);
       TreeNode* rightnode=solve(node->right,p,q);
       if(!leftnode)
       return rightnode;
       if(!rightnode)
       return leftnode;
       
       return node;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       return solve(root,p,q);
    }
}; 
class Solution {
public:
    void solve(TreeNode* node,int k,int &count,int &ans)
    {
       if(node==NULL)
       return ;
       solve(node->left,k,count,ans);
       count++;
       if(count==k)
       {
           ans= node->val;
           return;
       }
       solve(node->right,k,count,ans);
       return;
    }

    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int ans=0;
        solve(root,k,count,ans);
        return ans;
    }
};
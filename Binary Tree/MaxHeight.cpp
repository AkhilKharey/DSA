// https://leetcode.com/problems/maximum-depth-of-binary-tree/
class Solution {
public:
    void solve(TreeNode* node,int count,int &ans)
    {
      if(node==NULL)
      {
          count--;
          ans=max(ans,count);
          return;
      }
      count++;
      solve(node->left,count,ans);
      solve(node->right,count,ans);
      return; 
    }
    int maxDepth(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,1,ans);
        return ans;
    }
};
// --------------------------------------------------------------------approach 2
class Solution {
public:
    int maxDepth(TreeNode* root) {
         if(root==NULL)
         return 0;
        int leftHeight=maxDepth(root->left);
        int rightHeight=maxDepth(root->right);
        return 1+max(leftHeight,rightHeight);
    }
};
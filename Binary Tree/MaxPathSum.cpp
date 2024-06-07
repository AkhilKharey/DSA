class Solution {
public:
    int solve(TreeNode* node,int &sum)
    {
        if(node==NULL)
        {
            return 0;
        }
        //  ls and rs can come negative
        //  we dont want to take negative values of ls and rs
        // to avoid that take a maximum with 0 if negative value comes then just make the value 0
        int ls=max(0,solve(node->left,sum));
        int rs=max(0,solve(node->right,sum));

         sum=max(sum,node->val+ls+rs);

        return node->val +max(ls,rs) ;
    }

    int maxPathSum(TreeNode* root) {
        if(root==NULL)
        return 0;
        int sum=INT_MIN;
        solve(root, sum);
        return sum;
    }
};
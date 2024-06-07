class Solution {
public:
    int findDiameter(TreeNode* node, int &maxd)
    {
        if(node==NULL)
        return 0;
        int l=findDiameter(node->left,maxd);
        int r =findDiameter(node->right,maxd);

        int h=1+max(l,r);
        int temp=l+r;
        maxd=max(maxd,temp);
        return h;
    }
        int diameterOfBinaryTree(TreeNode* root) {
            int answer=INT_MIN;
        int ans=findDiameter(root,answer);
        return answer;
    }
};
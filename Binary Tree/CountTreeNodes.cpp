// -----------------------------------------------------approach1 using level  order traversal
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
        return 0;
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                  q.push(node->right);
                }
              ans++;
            }
        }
        return ans;
    }
};
// -------------------------------------------------------optimal approach using the property of complete binary tree
class Solution {
public:
   int findleftheight(TreeNode* node)
    {
        int ans=0;
        while(node)
        {
            ans++;
            node=node->left;
        }
        return ans;
    }
    int findrightheight(TreeNode* node)
    {
        int ans=0;
        while(node)
        {
            ans++;
            node=node->right;
        }
        return ans;

    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
        return 0;
        int lh=findleftheight(root);
        int rh=findrightheight(root);
        if(lh==rh)
        return (1<<lh)-1;
        else
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
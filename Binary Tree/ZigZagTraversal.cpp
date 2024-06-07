class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
        return ans;
        queue<TreeNode*>q;
        q.push(root);
       int count=0;
        while(!q.empty())
        {
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
               if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                level.push_back(node->val);
            }
            count++;
            // if count is odd then push directly
            if(count%2!=0)
            ans.push_back(level);
            // if count is even then push after reversing it
            else
            {
                reverse(level.begin(),level.end());
                ans.push_back(level);
            }
        }
        return ans;
    }
};
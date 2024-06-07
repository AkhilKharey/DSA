class Solution {
public:
    void markparents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parents)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            
                TreeNode* node=q.front();
                q.pop();
                if(node->left)
                {
                    parents[node->left]=node;
                    q.push(node->left);
                }
                if(node->right)
                {
                    parents[node->right]=node;
                    q.push(node->right);
                }
            
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parents;
        markparents(root,parents);
        queue<TreeNode*>q;
        q.push(target);
        int distance=0;
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        while(!q.empty())
        {
            int size=q.size();
            if(distance++==k)
            break;

            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left])
                {
                    visited[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right])
                {
                    visited[node->right]=true;
                    q.push(node->right);
                }
                if(parents[node] && !visited[parents[node]])
                {
                    visited[parents[node]]=true;
                    q.push(parents[node]);
                }
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            TreeNode* node=q.front();q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};
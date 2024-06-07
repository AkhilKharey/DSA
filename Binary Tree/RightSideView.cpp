class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)
        return ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        map<int,int>mp;
        mp[0]=root->val;
    while(!q.empty())
    {
        auto temp=q.front();
        q.pop();
        TreeNode* node=temp.first;
        int value=node->val;
        int level=temp.second;
        if(node->left)
        {
            mp[level+1]=node->left->val;
            q.push({node->left,level+1});
        }
        if(node->right)
        {
            mp[level+1]=node->right->val; 
            q.push({node->right,level+1});
        }

    }
    for(auto i:mp)
    {
        ans.push_back(i.second);
    }
    return ans;
    }
};
// -------------------------------------------------------------------------APROAACH 2 (RECURSIVE)
class Solution {
public:
     void solve(TreeNode* node,int level,vector<int> & ans)
     {
         if(node==NULL)
         {
         return;
         }
             
         if(level==ans.size())
         {
             ans.push_back(node->val);
         }
         solve(node->right,level+1,ans);
         solve(node->left,level+1,ans);
         return;
     }

    vector<int> rightSideView(TreeNode* root) {
       vector<int>ans;
       if(!root)
       return ans;
        solve(root,0,ans);
        return ans;

    }
};
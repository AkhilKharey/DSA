// wrong solution (overflow)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
         int ans=INT_MIN;
        while(!q.empty())
        {
            vector< int>indexes;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                q.pop();
                if(temp.first->left)
                q.push({temp.first->left,2*temp.second});
                if(temp.first->right)
                q.push({temp.first->right,2*temp.second+1});
                indexes.push_back(temp.second);
            }
               ans=max(ans,indexes.back()-indexes.front()+1);
        }
        return ans;
    }
};
//  -----------------------------------------------------------APPROACH2 WITH UPDATED INDEXES TO AVOID OVERFLOW
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
        return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            int minlevelindex=q.front().second;
            int first,last;
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                q.pop();
              long long updatedindex=temp.second-minlevelindex;
              if(i==0)
              first=updatedindex;
              if(i==size-1)
              last=updatedindex;
              if(temp.first->left)
              q.push({temp.first->left,updatedindex*2+1});
              if(temp.first->right)
              q.push({temp.first->right,updatedindex*2+2});

            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};
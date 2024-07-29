class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            TreeNode *node = temp.first;
            int vertical = temp.second.first;
            int level = temp.second.second;

            if (node->left)
            {
                q.push({node->left, {vertical - 1, level + 1}});
            }
            if (node->right)
            {
                q.push({node->right, {vertical + 1, level + 1}});
            }
            mp[vertical][level].insert(node->val);
        }
        vector<vector<int>> ans;
        for (auto v : mp)
        {
            vector<int> temp;
            for (auto l : v.second)
            {
                temp.insert(temp.end(), l.second.begin(), l.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
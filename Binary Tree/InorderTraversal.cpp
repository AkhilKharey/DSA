class Solution {
public:
    void inorder(TreeNode* root,vector<int>& ans)
    {
        if(root==NULL)
        return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return ans;
    }
};
// --------------------------------------APPROACH(ITERATIVE)
vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
        return ans;
        stack<TreeNode*>st;
        TreeNode* node=root;
        while(true)
        {
            if(node!=NULL)
            {
                st.push(node);
                node=node->left;
            }
            else
            {
                if(st.empty()) break;
                ans.push_back(st.top()->val);
                node=st.top()->right;
                st.pop();
            }
        }
        return ans;
    }
};
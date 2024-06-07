class Solution {
public:
    void preorder(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
        return;
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
    vector<int>ans;
    preorder(root,ans);
    return ans;


    }
};
// ---------------------------------------------------------ITERATIVE APPROACH
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>ans;
        if(root==NULL)
        return ans;
        st.push(root);
        while(!st.empty())
        {
            ans.push_back(st.top()->val);
            TreeNode* node=st.top();
            st.pop();
            if(node->right!=NULL) st.push(node->right);
            if(node->left!=NULL) st.push(node->left);
        }
        return ans;
    }
};
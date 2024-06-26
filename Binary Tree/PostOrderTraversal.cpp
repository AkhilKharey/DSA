// -----------------------------------------------------------Recursive Approach
class Solution {
public:
   void postorder(TreeNode* root,vector<int>& ans)
   {
       if(root==NULL)
       return;  
       postorder(root->left,ans);
       postorder(root->right,ans);
       ans.push_back(root->val);
   }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorder(root,ans);
        return ans;
    }
};
// -------------------------------------------------------Iterative Approach using 2 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
        return ans;
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        st1.push(root);
        while(!st1.empty())
        {
            TreeNode* node=st1.top();
            st1.pop();
            st2.push(node);
            if(node->left!=NULL) st1.push(node->left);
            if(node->right!=NULL) st1.push(node->right);
        }
        while(!st2.empty())
        {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};
// -------------------------------------------------------------------using a single stack
vector < int > postOrderTrav(node * cur) {

  vector < int > postOrder;
  if (cur == NULL) return postOrder;

  stack < node * > st;
  while (cur != NULL || !st.empty()) {

    if (cur != NULL) {
      st.push(cur);
      cur = cur -> left;
    } else {
      node * temp = st.top() -> right;
      if (temp == NULL) {
        temp = st.top();
        st.pop();
        postOrder.push_back(temp -> data);
        while (!st.empty() && temp == st.top() -> right) {
          temp = st.top(); 
          st.pop();
          postOrder.push_back(temp -> data);
        }
      } else cur = temp;
    }
  }
  return postOrder;

}
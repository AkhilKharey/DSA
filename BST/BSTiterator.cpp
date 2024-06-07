class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushleft(root);
    }
    
    int next() {
        TreeNode* tempnode=st.top();
        st.pop();
        pushleft(tempnode->right);
        return tempnode->val;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
    private:
   void pushleft(TreeNode* node)
    {
      while(node)
      {
          st.push(node);
          node=node->left;
      }
    }
};
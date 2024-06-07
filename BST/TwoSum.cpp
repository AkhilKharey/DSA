class Solution {
public:
    bool twosum(TreeNode* node,set<int>&set, int k)
    {
        if(node==NULL)
        return false;
        int moreneeded=k-node->val;
        if(set.find(moreneeded)!=set.end())
        return true;
        set.insert(node->val);
        if(twosum(node->left,set,k)||twosum(node->right,set,k))
        return true;
        else
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
       set<int>set;
        return twosum(root,set,k);
    }
};
// -----------------------------------------------------OPTIMAL APPROACH using 2 BST_ITERATOR
class BSTIterator {
    stack<TreeNode*> st;
    bool reverse=true;
public:
    BSTIterator(TreeNode* root,bool isReverse) {
        reverse=isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* tempnode=st.top();
        st.pop();
        if(!reverse)
        pushAll(tempnode->right);
        else
        pushAll(tempnode->left);
        return tempnode->val;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
    private:
   void pushAll(TreeNode* node)
    {
      while(node)
      {
          st.push(node);
          if(!reverse)
          node=node->left;
          else
          node=node->right;
      }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
        return false;
        // for next that is forward pointer
        BSTIterator l(root,false);
        // for before that is backward pointer
        BSTIterator r(root,true);

        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k)
            return true;
           else if(i+j<k)
            i=l.next();
            else
            j=r.next();
        }
        return false;
    }
};
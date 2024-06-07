class Solution {
 private:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
    private:
    void inorder(TreeNode* node)
    {
        if(!node)
        return;
        inorder(node->left);
        if(prev && node->val < prev->val)
        {
            if(first==NULL)
            {
                first=prev;
                middle=node;
            }
            else
            {
                last=node;
            }
        }
        prev=node;
        inorder(node->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        inorder(root);
        if(first && last)
        swap(first->val,last->val);
        else if(first && middle)
        swap(first->val, middle->val);
        return;
    }
};
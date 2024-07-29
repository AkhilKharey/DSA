class Solution
{
public:
    // ------------------------------------------------------------------------------inorder
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;
        TreeNode *curr = root;
        while (curr)
        {
            if (!curr->left)
            {
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *prev = curr->left;
                // go to the left subtree and then go to the extreme right
                //  which is the last guy in inorder of left subtree
                while (prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }
                // thread ni bani hai to thread banake left me janeka
                if (prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                // thread already  bani hai to thread hatake right me janeka
                if (prev->right == curr)
                {
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        // -------------------------------------------------------------------------preorder
        vector<int> preorder;
        TreeNode *curr = root;
        while (curr)
        {
            if (!curr->left)
            {
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                if (prev->right == curr)
                {
                    prev->right = NULL;

                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};
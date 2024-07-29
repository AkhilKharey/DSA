class Solution
{
public:
    TreeNode *inpost(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, unordered_map<int, int> &imap)
    {
        if (is > ie || ps > pe)
            return NULL;
        TreeNode *root = new TreeNode(postorder[pe]);
        int inroot = imap[postorder[pe]];
        int numsleft = inroot - is;
        root->left = inpost(inorder, is, inroot - 1, postorder, ps, ps + numsleft - 1, imap);
        root->right = inpost(inorder, inroot + 1, ie, postorder, ps + numsleft, pe - 1, imap);
        return root;
    }

        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() != postorder.size())
            return NULL;

        unordered_map<int, int> imap;
        for (int i = 0; i < inorder.size(); i++)
            imap[inorder[i]] = i;
        TreeNode *root = inpost(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, imap);
        return root;
    }
};
class Solution
{
public:
    void lca(TreeNode *node, TreeNode *&ans, TreeNode *p, TreeNode *q)
    {
        if (node == NULL)
            return;
        // dono opposite side hai
        if ((p->val <= node->val && node->val <= q->val) || (q->val <= node->val && node->val <= p->val))
        {
            ans = node;
            return;
        }
        // dono left me
        if (p->val < node->val && q->val < node->val)
            lca(node->left, ans, p, q);
        // dono right me
        if (p->val > node->val && q->val > node->val)
            lca(node->right, ans, p, q);
        return;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ans = NULL;
        lca(root, ans, p, q);
        return ans;
    }
};
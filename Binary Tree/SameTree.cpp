class Solution {
public:
    bool solve(TreeNode* node1,TreeNode* node2)
    {
        // dono me se koi ek null hua to false
        if(node1==NULL && node2!=NULL)
        return false;
        if(node1!=NULL && node2==NULL)
        return false;
        // dono null hue to true
        if(node1==NULL && node2==NULL)
        return true;
        // dono ki value alag alag hai to false single node wale case k liye
         if(node1->val!=node2->val)
         return false;
        //  dono ka left  null nhi hai aur value alag alag hai to false
        if(node1->left!=NULL && node2->left!=NULL)
        {
        if(node1->left->val!=node2->left->val)
        return false;
        }
        //  dono ka right  null nhi hai aur value alag alag hai to false
        if(node1->right!=NULL && node2->right!=NULL)
        {
        if(node1->right->val!=node2->right->val)
        return false;
        }
        // aage kisi bhi node se value false aati hai to false return kara denge 
        if(!solve(node1->left,node2->left))
        return false;
        if(!solve(node1->right,node2->right))
        return false;
        // agar aage kisi node se false ni aata to true return karaenge
        return true;
    } 
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};
// ------------------------------------------APPROACH SIMPLE 
class Solution {
public:
    bool solve(TreeNode* node1, TreeNode* node2)
    {
        if(node1==NULL || node2==NULL)
        return (node1==node2);

        if(node1->val!=node2->val)
        return false;
        if(!solve(node1->left,node2->left))
        return false;
        if(!solve(node1->right,node2->right))
        return false;
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};
// ---------------------------------------aur simple
class Solution {
public:
    bool solve(TreeNode* node1, TreeNode* node2)
    {
        if(node1==NULL || node2==NULL)
        return (node1==node2);

     return(node1->val==node2->val && solve(node1->left,node2->left) && solve(node1->right,node2->right));
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};
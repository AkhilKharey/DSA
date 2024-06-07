class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node* node=root;
        Node*ansnode=NULL;
        while(node)
        {
            
            if(x->data < node->data)
            {
                ansnode=node;
                node=node->left;
            }
            else
            {
                node=node->right;
            }
        }
        return ansnode;
    }
};
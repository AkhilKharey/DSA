class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
        return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL)
            s.append("NULL,");
            else
            {
              s.append(to_string(node->val)+',');
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
        

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    if(data.size()==0)
    return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode* root=new TreeNode(stoi(str));
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node=q.front();
        q.pop();
        // for left
        getline(s,str,',');
        if(str=="NULL")
        node->left=NULL;
        else
        {
            TreeNode* leftnode= new TreeNode(stoi(str));
            node->left=leftnode;
            q.push(leftnode);
        }
        // for right
        getline(s,str,',');
        if(str=="NULL")
        node->right=NULL;
        else
        {
            TreeNode* rightnode=new TreeNode(stoi(str));
            node->right=rightnode;
            q.push(rightnode);
        }

    }
    return root;
    }
};
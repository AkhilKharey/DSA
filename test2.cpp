#include <bits/stdc++.h>

using namespace std;

// Define the structure for the tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to create a binary tree from a vector
TreeNode *createTreeFromVector(const vector<string> &nodes)
{
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;

    TreeNode *root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    int index = 1;

    while (!nodeQueue.empty() && index < nodes.size())
    {
        TreeNode *current = nodeQueue.front();
        nodeQueue.pop();

        // Create left child
        if (nodes[index] != "null")
        {
            current->left = new TreeNode(stoi(nodes[index]));
            nodeQueue.push(current->left);
        }
        index++;

        // Create right child
        if (index < nodes.size() && nodes[index] != "null")
        {
            current->right = new TreeNode(stoi(nodes[index]));
            nodeQueue.push(current->right);
        }
        index++;
    }

    return root;
}

// Function to check if a binary tree is a valid BST
bool isValid(TreeNode *root)
{
    stack<TreeNode *> nodeStack;
    TreeNode *prev = nullptr;
    TreeNode *curr = root;

    while (curr != nullptr || !nodeStack.empty())
    {
        while (curr != nullptr)
        {
            nodeStack.push(curr);
            curr = curr->left;
        }

        curr = nodeStack.top();
        nodeStack.pop();

        // Check the BST property
        if (prev != nullptr && curr->val <= prev->val)
        {
            return false;
        }

        prev = curr;
        curr = curr->right;
    }

    return true;
}

bool isValidBST(const vector<string> &root)
{
    TreeNode *treeRoot = createTreeFromVector(root);
    return isValid(treeRoot);
}

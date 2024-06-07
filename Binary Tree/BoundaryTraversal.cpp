// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public: 
    bool isLeaf(Node* node)
    {
        if(node->left==NULL && node->right==NULL)
        return true;
        return false;
    }
    void addLeft(Node* node,vector<int>& ans)
    {
        Node* temp=node->left;
        while(temp!=NULL)
        {
            if(!isLeaf(temp)) ans.push_back(temp->data);
            if(temp->left) temp=temp->left;
            else
            temp=temp->right;
        }
    }
    void addLeaf(Node* node,vector<int>&ans)
    {
        if(isLeaf(node))
        {
            ans.push_back(node->data);
            return;
        }
       if(node->left) addLeaf(node->left,ans);
        if(node->right) addLeaf(node->right,ans);
        return;
    }
    void addRight(Node* node,vector<int>& ans)
    {
        Node* temp = node;
        vector<int>anstemp;
        while(temp!=NULL)
        {
            if(!isLeaf(temp))
            anstemp.push_back(temp->data);
            if(temp->right)
            temp=temp->right;
            else
            temp=temp->left;
        }
        reverse(anstemp.begin(),anstemp.end());
        for(int i=0;i<anstemp.size();i++)
        {
            ans.push_back(anstemp[i]);
        }
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(!root)
        return ans;
        if(!isLeaf(root))
        ans.push_back(root->data);
        addLeft(root,ans);
        addLeaf(root,ans);
        addRight(root->right,ans);
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
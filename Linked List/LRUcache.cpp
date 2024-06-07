class LRUCache {
public:
class Node{
    public:
      int key;
      int val;
      Node* next;
      Node* prev;
      Node(int _key,int _value)
      {
          key=_key;
          val=_value;
      }
};
Node* head=new Node(-1,-1);
Node* tail=new Node(-1,-1);
int cap;
unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
          cap=capacity;
          head->next=tail;
          tail->prev=head;
    }
    void addNode(Node* newNode)
    {
        Node* temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;

    }
    void deleteNode(Node* delNode)
    {
       Node* delnext=delNode->next;
        Node* delprev=delNode->prev;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        else
        {
            Node* temp=mp[key];
            int result=temp->val;
            mp.erase(key);
            deleteNode(temp);
            addNode(temp);
            mp[key]=head->next;
            return result;
        }
    }
    
    void put(int key, int value) {
            if(mp.find(key)!=mp.end())
            {
                Node* existingNode=mp[key];
                deleteNode(existingNode);
                mp.erase(key);
            }
            if(mp.size()==cap)
            {
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
            addNode(new Node(key,value));
            mp[key]=head->next;  
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
void reverse(queue<int>&q,int k,int i)
{
   
}
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int>st;
     for(int i=0;i<k;i++)
     {
         int temp=q.front();
         q.pop();
         st.push(temp);
     }
     while(!st.empty())
     {
         q.push(st.top());
         st.pop();
     }
     for(int i=0;i<q.size()-k;i++)
     {
         int temp=q.front();
         q.pop();
         q.push(temp);
     }
     return q;
}
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedInsert(stack<int>&st,int x)
{
    if(st.empty())
    {
        st.push(x);
        return;
    }
    
    else if(st.top()>x)
    {
        int temp=st.top();
    st.pop();
    SortedInsert(st,x);
    st.push(temp);
    return;
    }
    else
    {
        st.push(x);
        return;
    }
}
void solve(stack<int>&st)
{
    if(st.empty())
    {
        return;
    }
    int temp=st.top();
    st.pop();
    solve(st);
    SortedInsert(st,temp);
    return;
}
void SortedStack :: sort()
{
   //Your code here
   
   solve(s);
   
   
   
}
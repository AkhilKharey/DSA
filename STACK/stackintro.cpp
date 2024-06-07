#include<stack>
#include<iostream>
using namespace std;
int main()
{
    stack<int>s;
    s.push(2);
    s.push(1);
    s.push(3);
    cout<<"top element is"<<s.top()<<endl;
    s.pop();
    cout<<"top element is"<<s.top();
    
    
}
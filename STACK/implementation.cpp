#include<iostream>
using namespace std;
class stack{
// properties---------------------------using aray 
public:
    int *arr;
    int top;
    int size;
    // behaviour
    stack(int size)
    {
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int element)
    {
        if(size-top>1)
        {
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }

    }
    void pop(){
        if(top>=0)
        {
            top--;
        }
        else{
            cout<<"stack underflow"<<endl;
        }
     }
    int peak(){
      if(top>=0 )
      {
      return arr[top];
      }

      else
      {
      cout<<"stack is empty"<<endl;
      return -1;    
      }
    }
    bool isEmpty(){
   if(top==-1)
   return true;
   else
   return false;
    }
};
int main(){
     stack st(5);
     st.push(19);
     st.push(20);
     st.push(21);
     cout<<"top element beforw popping is "<<st.peak()<<endl;
     st.pop();
     cout<<"top element after popping is "<<st.peak()<<endl;    
    return 0;
}   
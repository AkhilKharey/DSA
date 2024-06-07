#include<iostream>
using namespace std;
void reverse(char name[],int n)
{
    int s=0;
    int e=n-1;
    while(s<e)
    {
        swap(name[s++],name[e--]);
    }
}
int stringlen(char name[]){
    int count=0;
    for(int i=0;name[i]!='\0';i++)
    count++;
    return count;
}
int main()
{
    char name[20];
    cin>>name;
    int l=stringlen(name);
    reverse(name,l);
    cout<<l<<endl;  
    cout<<name<<endl;
}
#include<iostream>
using namespace std;
char tolowercase(char ch){
    if(ch>='a'&&ch<='z')
    return ch;
    else{
    char temp=ch-'A'+'a';
    return temp;
    }
}
int checkpalindrome(char name[],int n)
{
    int s=0;
    int e=n-1;
    while(s<e)
    {
     if(tolowercase(name[s++])!=tolowercase(name[e--]))
     return 0;
    }
    return 1;
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
    cout<< checkpalindrome(name,l);
    
}
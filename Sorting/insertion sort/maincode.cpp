#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int a[100];
int i=0;
while(i<n)
{
    cin>>a[i];
    i++;
}
for(int i=1;i<n;i++)
{
    int temp=a[i];
    int j=i-1;
    for(;j>=0;j--)
    {
     if(temp<a[j])
     {
        //shift
        a[j+1]=a[j];

     }
     else{
        break;
     }
    }
    a[j+1]=temp;
}
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
return 0;
}                                                                                                                        
#include<bits/stdc++.h>
using namespace std;
void largestrowsum(int a[][3],int m,int n)
{
    int max_sum=0;
    int max_row=0;
  for(int i=0;i<3;i++)
  {
    int sum=0;
    for(int j=0;j<3;j++)
    {
    sum =sum+a[i][j];
    }
    if(sum>max_sum)
    {
        max_sum=sum;
        max_row=i;
    }
  }
  cout<<"max sum is"<<max_sum<<"from"<<max_row<<"row"<<endl;
  return;
}
int main(){
    int a[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<a[i][j]<<"";
        }
        cout<<endl;
    }

      largestrowsum(a,3,3);
    return 0;
}
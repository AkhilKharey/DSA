// finding the  kth prime
#include<iostream>
using namespace std;
int n=5000000;
bool  sieve[5000001];
int kthprime[5000001];
void createsieve()
{
    sieve[0]=sieve[1]=false;
    for(int i=2;i<=n;i++)
    {
    sieve[i]=true;
    }
    int count=0;
    for(int i=2;i*i<=n;i++)
    {
        if(sieve[i]==true)
        {
        kthprime[count]=i;
        count++;
        for(int j=i*i;j<=n;j=j+i)
        {
            sieve[j]=false;
        }
        }
    }
}
 

int main()
{
int t;
cin>>t;
createsieve();
while(t--)
{
int k;
cin>>k;
int temp=k-1;
cout<<kthprime[temp]<<endl;

    
}
return 0;
}

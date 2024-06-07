// // you are given a range lets say 1e6 and a number n and you have to tell how many numbers in the range(1-1e6) have the minimum prime factor as n
// #include<iostream>
// using namespace std;
// int n=1e6;
// bool sieve[100001];
// int count[100001];
// void createsieve()
// {
//     sieve[0]=sieve[1]=false;
//     for(int i=0;i<n;i++)
//     count[i]=0;
//     for(int i=2;i<=n;i++)
//     {
//     sieve[i]=true;
//     }
//     for(int i=2;i*i<=n;i++)
//     {
//         if(sieve[i]==true)
//         {
//             count[i]++;
//             for(int j=i*i;j<=n;j=j+i)
//             {
//                 count[i]++;
//                 sieve[j]=false;

//             }
//         }
//     }

// }

// int main()
// {
//           int  t;
//           cin>>t;
//           while(t--)
//           {
//             createsieve();
//             int q;
//             cin>>q;
//             cout<<count[q];
//           }
#include<iostream>
using namespace std;
int n=1e6;
int sieve[100001];
void createsieve()
{
    sieve[0]=sieve[1]=0;
    for(int i=0;i<=n;i++)
    {
        sieve[i]=1;
    }
    for(int i=2;i*i<=n;i++)
    {
        if(sieve[i]==1)
        {
            for(int j=i*i;j<=n&&sieve[j]==1;j=j+i)
            {
              sieve[j]=0;
              sieve[i]++;
            }
        }
    }
}
int main()
{
int t;
cin>>t;
while(t--)
{
int prime_num;
cin>>prime_num;
cout<<sieve[prime_num]<<endl;
}
}
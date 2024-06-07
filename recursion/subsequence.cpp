
#include<iostream>
#include<vector>
using namespace std;
void printsubs(int i,vector<int>&ds,int arr[], int n)
{
    if(i==n)
    {
        for(int it:ds){
        cout<<it<<"";
        }
        cout<<endl; 
        return;
    }
    ds.push_back(arr[i]);
    printsubs(i+1,ds,arr,n);
    ds.pop_back();
    printsubs(i+1,ds,arr,n);
}
int main(){
    vector<int>ds;
    int arr[]={3,2,1};
    int n=3;
    printsubs(0,ds,arr,sizeof(arr)/sizeof(int));
    return 0;
}
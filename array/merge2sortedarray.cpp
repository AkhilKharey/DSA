#include<bits/stdc++.h>
using namespace std;
void merge(int arr1[],int n,int arr2[],int m,int arr3[])
{
    int i,j=0;int k=0;
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            arr3[k]=arr1[i];
            i++;
            k++;
        }
        else if(arr1[i]>arr2[j])
        {
            arr3[k]=arr2[j];
            j++;
            k++;
        }
        else
        {
            arr3[k]=arr1[i];

            i++;
            j++;
            k++;
        }
    }
    while(i<n)
    arr3[k++]=arr1[i];
    while(j<m)
    arr3[k++]=arr2[j];
    
}
// void print(int arr3[],int n)
// {
//  for(int i=0;i<n;i++)
//  cout<<arr3[i]<<" ";
 
// }

int main(){
    int arr1[5]={1,2,3,4,6};
    int arr2[6]={4,5,6,7,8,9};
    int arr3[11]={0};  
     int i=0,j=0;int k=0;
    while(i<5 && j<6)
    {
        if(arr1[i]<arr2[j])
        {
            arr3[k]=arr1[i];
            i++;
            k++;
        }
        else if(arr1[i]>arr2[j])
        {
            arr3[k]=arr2[j];
            j++;
            k++;
        }
        else
        {
            arr3[k++]=arr1[i];
            arr3[k++]=arr1[i];
            i++;
            j++;
            
        }
    }
    while(i<5){
    arr3[k++]=arr1[i++];
    }
    while(j<6)
    {

    arr3[k++]=arr2[j++];
    }
    
     for(int i=0;i<11;i++)
     cout<<arr3[i]<<" ";

    return 0;
}
// ---------------------optimised approach
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int lptr=m-1;
        int rptr=0;
        while(lptr>=0 && rptr<n)
        {
            if(nums1[lptr]<=nums2[rptr])
            break;
            else
            {
                swap(nums1[lptr],nums2[rptr]);
                lptr--;
                rptr++;
            }
        }
        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.end());
        int j=0;
        for(int i=m;i<nums1.size();i++)
        {
           
            nums1[i]=nums2[j++];
        }


    }
};
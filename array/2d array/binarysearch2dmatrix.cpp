// https://leetcode.com/problems/search-a-2d-matrix/description/
#include<iostream>
using namespace std;
int main()
{
    int m,n;
    int target;
    cin>>m;
    cin>>n;
    cin>>target;
    int matrix[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {

        cin>>matrix[i][j];
        }
    }
    int s=0;
    int e=m*n-1;
    int mid=s+(e-s)/2;
    while(s<=e)
    {
   int element=matrix[mid/n][mid%n];
//    for getting row divide by  number of columns and for getting column mod by number of columns
   if(element==target)
   {
    cout<<"found";
    return 0;
   }
  else if(element>target)
   e=mid-1;
   else{
    s=mid+1;
   }
   mid=s+(e-s)/2;
    }

cout<<"not found";
return 0;
}
// approach 2
// // class Solution {
// public:
// int findtarget(vector<int>& matrix,int target)
// {
//     int s=0;
//     int e=matrix.size()-1;
//     int mid=s+(e-s)/2;
//     while(s<=e)
//     {
//         if(matrix[mid]>target)
//         e=mid-1;
//         else if(matrix[mid]<target)
//         s=mid+1;
//         else if(matrix[mid]==target)
//         return 1;
//         mid=s+(e-s)/2;

//     }
//     return 0;
//     }
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m=matrix.size();
//         int n=matrix[0].size();
//         int s=0;
//         int e=m-1;
//         int mid=s+(e-s)/2;
//         while(s<=e)
//         {
//             if(matrix[mid][0]>target)
//             e=mid-1;
//             else if(matrix[mid][0]<target)
//             {
//                 if(matrix[mid][0]<target&&matrix[mid][n-1]>=target)
//                 {
//                    if(findtarget(matrix[mid],target)==1)
//                    return true;
//                    else
//                    return false;
//                 }
//                 else
//                 {
//                     s=mid+1;

//                 }
//             }
//             else if(matrix[mid][0]==target)
//             return true;
//             mid=s+(e-s)/2;
//         }
//         return false;
//     }
// // };
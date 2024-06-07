// //{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;
// #define MAX 1000


// // } Driver Code Ends
// /*You are required to complete this method*/

// class Solution{
//   public:
//   vector<int> nextSmallerElements(int* heights,int n)
//      { 
//          vector<int>ans(n);
//         stack<int>st;
//         st.push(-1);
//         for(int i=n-1;i>=0;i--)
//         {
//             int temp=heights[i];
            
//                 while(st.top()!=-1 && heights[st.top()]>=temp)
//                 {
//                     st.pop();
//                 }
                
//                 ans[i]=st.top();
//                 st.push(i);
            
//         }
       
//         return ans;

//      }
//      vector<int> prevSmallerElements(int* heights,int n)
//      {
//         vector<int>ans(n);
//         stack<int>st;
//         st.push(-1);
//         for(int i=0;i<n;i++)
//         {
//             int temp=heights[i];
            
//                 while(st.top()!=-1 && heights[st.top()]>=temp)
//                 {
//                     st.pop();
//                 }
                
//                 ans[i]=st.top();
//                 st.push(i);
            
//         }
       
//         return ans;
//      }
//    int largestRectangleArea(int* heights,int n) {
//         vector<int>next(n);
//         next=nextSmallerElements(heights,n); 
//         vector<int>prev(n);
//         prev=prevSmallerElements(heights,n);
//         int area=INT_MIN;
//         for(int i=0;i<n;i++)
//         {
//             int length=heights[i];
//             if(next[i]==-1)
//             next[i]=n;
//             int breadth=next[i]-prev[i]-1;
//             int newarea=length*breadth;
//             area=max(area,newarea);
//         }
//         return area;
//    }
   
//     int maxArea(int M[MAX][MAX], int n, int m) {
//         // Your code here
//         int area=largestRectangleArea(M[0],m);
//         for(int i=1;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(M[i][j]!=0)
//                 M[i][j]+=M[i-1][j];
//                 else
//                 M[i][j]=0;
                
//             }
//             int newarea=largestRectangleArea(M[i],m);
//             area=max(area,newarea);
//         }
//         return area;
//     }
// };


// //{ Driver Code Starts.
// int main() {
//     int T;
//     cin >> T;

//     int M[MAX][MAX];

//     while (T--) {
//         int n, m;
//         cin >> n >> m;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 cin >> M[i][j];
//             }
//         }
//         Solution obj;
//         cout << obj.maxArea(M, n, m) << endl;
//     }
// }

// // } Driver Code Ends
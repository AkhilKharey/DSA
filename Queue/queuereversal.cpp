// // // ------------------------------------------------------------APPROACH1
// // class Solution
// // {
// //     public:
// //     queue<int> rev(queue<int> q)
// //     {
// //         // add code here.
// //         stack<int>st;
// //         while(!q.empty())
// //         {
// //             int x=q.front();
// //             q.pop();
// //             st.push(x);
// //         }
// //         while(!st.empty())
// //         {
// //             int x=st.top();
// //             st.pop();
// //             q.push(x);
// //         }
// //         return q;
// //     }
// // };
// // -------------------------------------------------------------------APPROACH 2 USING RECURSION
// //{ Driver Code Starts
// //Initial Template for C++

// #include<bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// //function Template for C++

// //Function to reverse the queue.
// class Solution
// {
//     public:
//     void reverse(queue<int>&q)
//     {
//         if(q.empty())
//         return;
//         int temp=q.front();
//         q.pop();
//         reverse(q);
//         q.push(temp);
//         return;
//     }
//     queue<int> rev(queue<int> q)
//     {
//         // add code here.
//         reverse(q);
//         return q;
//     }
// };



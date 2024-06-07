// // https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// You have N books, each with A[i] number of pages. M students need to be allocated contiguous books, with each student getting at least one book.
// Out of all the permutations, the goal is to find the permutation where the student with the most books allocated to him gets the minimum number of pages, out of all possible permutations.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 

// Example 1:

// Input:
// N = 4
// A[] = {12,34,67,90}
// M = 2
// Output:113
// Explanation:Allocation can be done in 
// following ways:
// {12} and {34, 67, 90} Maximum Pages = 191
// {12, 34} and {67, 90} Maximum Pages = 157
// {12, 34, 67} and {90} Maximum Pages =113.
// Therefore, the minimum of these cases is 113,
// which is selected as the output.

// Example 2:

// Input:
// N = 3
// A[] = {15,17,20}
// M = 2
// Output:32
// Explanation: Allocation is done as
// {15,17} and {20}
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findPages() which takes 2 Integers N, and m and an array A[] of length N as input and returns the expected answer.


// Expected Time Complexity: O(NlogN)
// Expected Auxilliary Space: O(1)


// Constraints:
// 1 <= N <= 105
// 1 <= A [ i ] <= 106
// 1 <= M <= 105

//  ------------------------------------------------LINEAR SEARCH SOLUTION
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int A[],int pages,int M,int N)
    {
        int stu=1;
        int stupages=0;
        for(int i=0;i<N;i++)
        {
            if(A[i]+stupages<=pages)
            {
                stupages+=A[i];
            }
            else
            {
                stu++;
                stupages=A[i];
            }
        }
        
        if(stu<=M)
        return true;
        else
        return false;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M)
        return -1;
        int low=*max_element(A,A+N);
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
        }
       int high=sum;
       int mid =low+(high-low)/2;
       for(int i=low;i<=high;i++)
       {
           if(isPossible(A,i,M,N))
           return i;
       }
        
    }
};
// -----------------------------------------------BINARY SEARCH SOLUTION
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int studentCount(int A[],int pages,int N)
    {
        int stu=1;
        int stupages=0;
        for(int i=0;i<N;i++)
        {
            if(A[i]+stupages<=pages)
            {
                stupages+=A[i];
            }
            else
            {
                stu++;
                stupages=A[i];
            }
        }
        return stu;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M)
        return -1;
        int low=*max_element(A,A+N);
       int high=accumulate(A,A+N,0);
       int mid =low+(high-low)/2;
       while(low<=high)
       {
           if(studentCount(A,mid,N)<=M)
           high=mid-1;
           else 
           low=mid+1;
            mid =low+(high-low)/2;
       }
       return low;
    }
};



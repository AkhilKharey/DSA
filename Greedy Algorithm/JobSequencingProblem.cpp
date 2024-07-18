// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job f
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    static bool comp(Job val1, Job val2)
    {
        return (val1.profit > val2.profit);
    }
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        // sort according to the profit
        sort(arr, arr + n, comp);
        int maxDeadline = 0;
        for (int i = 0; i < n; i++)
        {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        int hash[maxDeadline + 1];
        memset(hash, -1, sizeof(hash));
        int totalProfit = 0, count = 0;
        // iterate all the jobs
        for (int i = 0; i < n; i++)
        {
            // find a free slot for the ith job andd dlot could be from deadline to 0
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (hash[j] == -1)
                {
                    count++;
                    totalProfit += arr[i].profit;
                    hash[j] = arr[i].id;
                    break;
                }
            }
        }
        return {count, totalProfit};
    }
};

//{ Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends
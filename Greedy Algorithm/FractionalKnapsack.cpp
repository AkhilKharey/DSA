// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    bool static comp(Item val1, Item val2)
    {
        if ((static_cast<double>(val1.value) / val1.weight) >= (static_cast<double>(val2.value) / val2.weight))
            return true;
        return false;
    }
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        // Your code here
        // arrange in descending order of value/weight
        sort(arr, arr + n, comp);
        double totalValue = 0;
        for (int i = 0; i < n; i++)
        {
            // if weifght is less than size of knapsack then directly add
            if (arr[i].weight <= w)
            {
                totalValue += static_cast<double>(arr[i].value);
                w -= arr[i].weight;
            }
            // if weight is more then add as much it can accomodate and break out of the loop
            else
            {
                double fractionalValue = (static_cast<double>(arr[i].value) / arr[i].weight) * w;
                totalValue += fractionalValue;
                break;
            }
        }
        return totalValue;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--)
    {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
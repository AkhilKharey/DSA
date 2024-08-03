// #include <bits/stdc++.h>
// using namespace std;

// Function to find the smallest index of array elements
// whose removal makes the sum of odd and even indexed array elements equal
// void removeIndicesToMakeSumEqual(vector<int> &arr)
// {
//     // Stores size of array
//     int N = arr.size();

//     // Store prefix sum of odd
//     // index array elements
//     vector<int> odd(N, 0);

//     // Store prefix sum of even
//     // index array elements
//     vector<int> even(N, 0);

//     // Update even[0]
//     even[0] = arr[0];

//     // Traverse the given array
//     for (int i = 1; i < N; i++)
//     {

//         // Update odd[i]
//         odd[i] = odd[i - 1];

//         // Update even[i]
//         even[i] = even[i - 1];

//         // If the current index
//         // is an even number
//         if (i % 2 == 0)
//         {

//             // Update even[i]
//             even[i] += arr[i];
//         }

//         // If the current index
//         // is an odd number
//         else
//         {

//             // Update odd[i]
//             odd[i] += arr[i];
//         }
//     }

//     // Initialize the smallest index to a large value
//     int smallestIndex = INT_MAX;

//     // Store odd indices sum by
//     // removing 0-th index
//     int p = odd[N - 1];

//     // Store even indices sum by
//     // removing 0-th index
//     int q = even[N - 1] - arr[0];

//     // If p and q are equal
//     if (p == q)
//     {
//         smallestIndex = min(smallestIndex, 0);
//     }

//     // Traverse the array arr[]
//     for (int i = 1; i < N; i++)
//     {

//         // If i is an even number
//         if (i % 2 == 0)
//         {

//             // Update p by removing
//             // the i-th element
//             p = even[N - 1] - even[i - 1] - arr[i] + odd[i - 1];

//             // Update q by removing
//             // the i-th element
//             q = odd[N - 1] - odd[i - 1] + even[i - 1];
//         }
//         else
//         {

//             // Update q by removing
//             // the i-th element
//             q = odd[N - 1] - odd[i - 1] - arr[i] + even[i - 1];

//             // Update p by removing
//             // the i-th element
//             p = even[N - 1] - even[i - 1] + odd[i - 1];
//         }

//         // If odd index values sum is equal
//         // to even index values sum
//         if (p == q)
//         {
//             smallestIndex = min(smallestIndex, i);
//         }
//     }

//     // If no index found
//     if (smallestIndex == INT_MAX)
//     {
//         // Print not possible
//         cout << -1;
//     }
//     else
//     {
//         // Print the smallest index
//         cout << smallestIndex;
//     }
// }

// // Driver Code
// int main()
// {
//     vector<int> arr = {2, 5, 3, 1};
//     removeIndicesToMakeSumEqual(arr);

//     return 0;
// }
// C++ program to implement
// the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find indices of array elements
// whose removal makes the sum of odd and
// even indexed array elements equal
void removeIndicesToMakeSumEqual(vector<int> &arr)
{
    // Stores size of array
    int N = arr.size();

    // Store prefix sum of odd
    // index array elements
    vector<int> odd(N, 0);

    // Store prefix sum of even
    // index array elements
    vector<int> even(N, 0);

    // Update even[0]
    even[0] = arr[0];

    // Traverse the given array
    for (int i = 1; i < N; i++)
    {

        // Update odd[i]
        odd[i] = odd[i - 1];

        // Update even[i]
        even[i] = even[i - 1];

        // If the current index
        // is an even number
        if (i % 2 == 0)
        {

            // Update even[i]
            even[i] += arr[i];
        }

        // If the current index
        // is an odd number
        else
        {

            // Update odd[i]
            odd[i] += arr[i];
        }
    }

    // Check if at least one
    // index found or not that
    // satisfies the condition
    bool find = 0;
    // Store odd indices sum by
    // removing 0-th index
    int p = odd[N - 1];

    // Store even indices sum by
    // removing 0-th index
    int q = even[N - 1] - arr[0];

    // If p and q are equal
    if (p == q)
    {
        cout << "0 ";
        find = 1;
    }

    // Traverse the array arr[]
    for (int i = 1; i < N; i++)
    {

        // If i is an even number
        if (i % 2 == 0)
        {

            // Update p by removing
            // the i-th element
            p = even[N - 1] - even[i - 1] - arr[i] + odd[i - 1];

            // Update q by removing
            // the i-th element
            q = odd[N - 1] - odd[i - 1] + even[i - 1];
        }
        else
        {

            // Update q by removing
            // the i-th element
            q = odd[N - 1] - odd[i - 1] - arr[i] + even[i - 1];

            // Update p by removing
            // the i-th element
            p = even[N - 1] - even[i - 1] + odd[i - 1];
        }

        // If odd index values sum is equal
        // to even index values sum
        if (p == q)
        {

            // Set the find variable
            find = 1;

            // Print the current index
            cout << i << " ";
        }
    }

    // If no index found
    if (!find)
    {

        // Print not possible
        cout << -1;
    }
}

// Driver Code
int main()
{
    vector<int> arr = {2, 5, 3, 1};
    removeIndicesToMakeSumEqual(arr);

    return 0;
}

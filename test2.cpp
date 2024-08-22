#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(int N, vector<int> A, int Q, vector<vector<int>> Queries)
{
    vector<int> results;

    // Process each query
    for (const auto &query : Queries)
    {
        if (query.size() == 4)
        { // Type 2 Query (L R X)
            int L = query[1];
            int R = query[2];
            int X = query[3];
            int found = -1;

            // Search in the specified range
            for (int i = L - 1; i <= R - 1; ++i)
            {
                if (A[i] <= X)
                {
                    found = i + 1; // Convert back to 1-based index
                    break;
                }
            }
            results.push_back(found);
        }
        else if (query.size() == 3)
        { // Type 1 Query (L X)
            int L = query[1];
            int X = query[2];
            A[L - 1] = X; // Update the value at index L-1
        }
    }

    return results;
}

int main()
{
    // Test case directly added
    int N = 10;
    vector<int> A = {12, 71, 80, 22, 48, 13, 75, 81, 68, 51};
    int Q = 4;
    vector<vector<int>> Queries = {
        {2, 1, 10, 27}, // Query 1: Find first index in range [1, 10] where value ≤ 27
        {1, 2, 49},     // Query 2: Update index 2 to 49
        {1, 3, 26},     // Query 3: Update index 3 to 26
        {2, 2, 10, 7}   // Query 4: Find first index in range [2, 10] where value ≤ 7
    };

    vector<int> results = solve(N, A, Q, Queries);
    for (int result : results)
    {
        cout << result << endl;
    }

    return 0;
}

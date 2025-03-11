#include <bits/stdc++.h>
using namespace std;

// Function to compute minimum replacements for each string in the array
vector<int> minimalOperations(vector<string> words)
{
    vector<int> result;

    for (const string &s : words)
    {
        int n = s.length();
        int ans = 0;
        int i = 0;

        while (i < n)
        {
            int j = i;

            // Move j until characters s[i] & s[j] are unequal or end of string is reached
            while (j < n && s[j] == s[i])
            {
                j++;
            }

            // Compute the length of contiguous substring with equal characters
            int diff = j - i;

            // Minimum operations required to make adjacent characters unequal
            ans += diff / 2;
            i = j;
        }

        result.push_back(ans);
    }

    return result;
}

// Driver code
int main()
{
    vector<string> words = {"ab", "aab", "abb", "abab", "abaaaba"};
    vector<int> results = minimalOperations(words);

    for (int res : results)
    {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
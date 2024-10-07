// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	string FirstNonRepeating(string A)
	{
		// Code here
		string ans;
		unordered_map<char, int> count;
		queue<char> q;
		for (auto i : A)
		{
			count[i]++;

			if (count[i] <= 1)
			{
				q.push(i);
			}
			while (!q.empty() && count[q.front()] > 1)
			{
				q.pop();
			}
			if (!q.empty())
				ans.push_back(q.front());
			else
				ans.push_back('#');
		}
		return ans;
	}
};

//{ Driver Code Starts.
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
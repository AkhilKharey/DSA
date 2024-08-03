//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
	void pushZerosToEnd(int arr[], int n)
	{
		// code here
		int first = 0;
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] == 0)
			{

				first = i;
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			return;
		}
		int start = first + 1;
		for (int i = start; i < n; i++)
		{
			// first zero ka index pakad ke rakhenge aur swap kar denge non zero element mileto
			if (arr[i] != 0)
			{
				swap(arr[i], arr[first]);
				first++;
			}
		}
	}
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, i;
		cin >> n;
		int arr[n];
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		Solution ob;
		ob.pushZerosToEnd(arr, n);
		for (i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
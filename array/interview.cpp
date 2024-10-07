#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0;
    int r = a.size() - 1;
    while (l < r)
    {
        swap(a[l], a[r]);
        l++;
        r--;
    }
    for (auto i : a)
    {
        cout << i << " ";
    }
    return 0;
}
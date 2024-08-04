#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1000000000000
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define S second
#define F first
#define boost1 ios::sync_with_stdio(false);
#define boost2 cin.tie(0);
#define mem(a, val) memset(a, val, sizeof a)
#define endl "\n"
#define maxn 100001

int n, m, gc[21][21], dp[maxn][21];
vector<int> v[maxn];

void dfs(int cur, int par)
{
    vector<int> children;
    for (int i = 0; i < v[cur].size(); i++)
    {
        int x = v[cur][i];
        if (x == par)
            continue;
        dfs(x, cur);
        children.pb(x);
    }
    if (!children.size())
    {
        dp[cur][1] = 1;
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        dp[cur][i] = 1;
        for (auto it : children)
        {
            ll temp = 0;
            for (int j = 1; j <= m; j++)
            {
                temp += dp[it][gc[i][j]];
                if (temp >= mod)
                    temp -= mod;
            }
            dp[cur][i] = (dp[cur][i] * temp) % mod;
        }
    }
}
int main()
{
    boost1;
    boost2;
    int i, j, x, y;
    ll ans = 0;
    cin >> n >> m;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= m; j++)
            gc[i][j] = __gcd(i, j);
    }
    vector<int> p(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 1; i < n; i++)
    {

        v[p[i]].pb(i + 1);
        v[i + 1].pb(p[i]);
    }

    dfs(1, -1);
    for (i = 1; i <= m; i++)
    {
        ans += dp[1][i];
        if (ans >= mod)
            ans -= mod;
    }
    cout << ans;
    return 0;
}
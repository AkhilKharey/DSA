// https://leetcode.com/problems/assign-cookies/
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int m = s.size();
        int n = g.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l = 0;
        int r = 0;
        int ans = 0;
        while (l < m && r < n)
        {
            if (s[l] >= g[r])
            {
                // it means it can ssatisfy the greed of the student
                r += 1;
                ans++;
            }
            l += 1;
        }
        return ans;
    }
};
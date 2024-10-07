// recursive approach to print the length of the longest common subsequence
// https://leetcode.com/problems/longest-common-subsequence/
class Solution
{
public:
    int solve(string text1, string text2, int ind1, int ind2)
    {

        // if any index is less than 0  means any one of them is finished thus no need to compare further so return 0
        if (ind1 < 0 || ind2 < 0)
            return 0;
        // if the character matches then add 1 to the answer and move further
        if (text1[ind1] == text2[ind2])
            return 1 + solve(text1, text2, ind1 - 1, ind2 - 1);
        else
            // if the character doesn't matches then fix 1 index and move another and take max
            return 0 + max(solve(text1, text2, ind1 - 1, ind2), solve(text1, text2, ind1, ind2 - 1));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int ind1 = text1.length() - 1;
        int ind2 = text2.length() - 1;
        return solve(text1, text2, ind1, ind2);
    }
};
// memoization approach
class Solution
{
public:
    int solve(string &text1, string &text2, int ind1, int ind2, vector<vector<int>> &dp)
    {
        if (ind1 < 0 || ind2 < 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if (text1[ind1] == text2[ind2])
            return dp[ind1][ind2] = 1 + solve(text1, text2, ind1 - 1, ind2 - 1, dp);
        else
            return dp[ind1][ind2] = 0 + max(solve(text1, text2, ind1 - 1, ind2, dp), solve(text1, text2, ind1, ind2 - 1, dp));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int ind1 = text1.length();
        int ind2 = text2.length();
        vector<vector<int>> dp(ind1, vector<int>(ind2, -1));
        return solve(text1, text2, ind1 - 1, ind2 - 1, dp);
    }
};
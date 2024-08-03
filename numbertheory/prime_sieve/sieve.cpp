class Solution
{
    // counting prime number till n #optimised public :
    // TC-O(NLOG(LOGN)) PRIME HARMONIC SERIES
    int countPrimes(int n)
    {
        int count = 0;
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        // i*i <=n isliye lagaya hai kyuki inner loop me h ye condition
        for (int i = 2; i * i <= n; i++)
        {
            if (prime[i])
            {
                count++;
                // i*2 ki jagah i*i se start karna hai kyuki i*i se phle wale to sare already mark honge
                for (int j = i * i; j <= n; j = j + i)
                {
                    prime[j] = false;
                }
            }
        }
        return count;
    }
};
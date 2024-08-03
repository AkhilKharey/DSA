#include <iostream>
#include <vector>
#include <math>
using namespace std;
int n = 1e6;
bool sieve[100001];
void createsieve()
{
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= n; i++)
    {
        sieve[i] = true;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                sieve[j] = false;
            }
        }
    }
}
vector<int> generateprimes(int n)
{
    vector<int> ds;
    for (int i = 2; i < n; i++)
    {
        if (sieve[i] == true)
            ds.push_back(i);
    }
    return ds;
}
int main()
{
    int t;
    cin >> t;
    createsieve();
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        //   generate all primes till sqrt(r);
        vector<int> primes = generateprimes(sqrt(r));
        // create a dummy array of sizer-l+1 mark all as one
        int dummy[r - l + 1];
        for (int i = 0; i < r - l + 1; i++)
        {
            dummy[i] = 1;
        }
        // for all primes mark its multiple as false
        for (auto pr : primes)
        {
            // smallest multiple of pr in the range l to r
            int firstmultiple = (l / pr) * pr;
            // if smallest multiple is less than l
            if (firstmultiple < l)
                firstmultiple += pr;
            for (int j = max(firstmultiple, pr * pr); j <= r; j = j + pr)
            {
                dummy[j - l] = 0;
            }
        }
        for (int i = l; i <= r; i++)
        {
            if (dummy[i - l] == 1)
                cout << i << " ";
        }
        cout << endl;
    }
}
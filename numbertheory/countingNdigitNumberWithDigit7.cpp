#include <iostream>
#define MOD 1000000007

using namespace std;
// count number of n digit number with at least one digit as 7
// Function to calculate power with modulo
long long power(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int countWays(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    // Find all n digits numbers
    long long t = (9 * power(10, n - 1, MOD)) % MOD;

    // Find n digits number in which no 7 occurs
    long long h = (8 * power(9, n - 1, MOD)) % MOD;

    // Calculate the required value as the difference of the above two values
    long long r = (t - h + MOD) % MOD;

    return static_cast<int>(r);
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << countWays(n) << endl;

    return 0;
}

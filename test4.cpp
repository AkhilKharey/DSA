#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long int64;

int ArithmeticEquation(int N)
{
    bool *prime = new bool[N + 1];
    for (int i = 1; i <= N; i++)
        prime[i] = 1;

    int64 answer = 1;
    for (int p = 2; p <= N; p++)
    {
        if (prime[p])
        {
            for (int j = 2 * p; j <= N; j += p)
                prime[j] = 0;

            int64 e = 0;
            for (int64 j = p; j <= N; j *= p)
                e += N / j;

            answer = (answer * (1 + 2 * e)) % 1000007;
        }
    }

    delete[] prime; // Free allocated memory
    return answer;
}

int main()
{
    int n;
    cout << "Enter a value for n: ";
    cin >> n;

    int result = ArithmeticEquation(n);
    cout << "Result: " << result << endl;

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compute gcd using Euclidean algorithm
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to compute the power of a number modulo n
long long power(long long base, int exp, int n)
{
    long long result = 1;
    for (int i = 0; i < exp; i++)
    {
        result = (result * base) % n;
    }
    return result;
}

int main()
{
    // Two prime numbers
    double p = 61;
    double q = 53;
    double n = p * q;
    double e;
    double d;
    double phi = (p - 1) * (q - 1);

    // Public key (e, n)
    // Choosing e such that 1 < e < phi and gcd(e, phi) = 1
    for (int i = 2; i < phi; i++)
    {
        if (gcd(i, phi) == 1)
        {
            e = i;
            break;
        }
    }

    // Private key (d, n)
    // Computing d such that (d * e) % phi = 1
    for (int i = 1; i < phi; i++)
    {
        if (fmod(i * e, phi) == 1)
        {
            d = i;
            break;
        }
    }

    // Message to be encrypted
    double msg = 89;
    printf("Message data = %lf\n", msg);

    // Encryption C = (M^e) % n
    double c = power(msg, e, n);
    printf("Encrypted data = %lf\n", c);

    // Decryption M = (C^d) % n
    double m = power(c, d, n);
    printf("Decrypted data = %lf\n", m);

    return 0;
}

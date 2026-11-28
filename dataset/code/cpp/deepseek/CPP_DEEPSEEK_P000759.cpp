Here is the C++ code that you can use:

#include <iostream>
using namespace std;

long long int power(long long int a, long long int b, long long int mod)
{
    if(b == 0)
        return 1;
    long long int temp = power(a, b/2, mod);
    if(b%2 == 0)
        return (temp*temp) % mod;
    else
        return ((a*temp)%mod * temp) % mod;
}

long long int solve(long long int n, long long int mod)
{
    if(n == 0)
        return 1;
    else if(n == 1)
        return 2;
    else if(n%2 == 0)
    {
        long long int temp = power(10, n/2, mod);
        return (temp*(power(10, (n+1)/2, mod) - 1) % mod + mod) % mod;
    }
    else
    {
        long long int temp = power(10, n/2, mod);
        return (temp*(power(10, (n+1)/2, mod) - 1) % mod + mod) % mod;
    }
}

int main()
{
    long long int n;
    cin >> n;
    long long int mod = 1000000007;
    cout << solve(n, mod) << endl;
    return 0;
}

The code uses recursive exponentiation to solve the problem. The function `power(a, b, mod)` calculates `a` to the power `b` modulo `mod`. The function `solve(n, mod)` calculates the total number of good digit strings of length `n` modulo `mod`. If `n` is even, it calculates the total number of good digit strings of length `n/2` (removing the last digit). If `n` is odd, it calculates the total number of good digit strings of length `n/2` (removing the last digit and including the last digit). The function `main()` reads `n` from the input and prints the result.
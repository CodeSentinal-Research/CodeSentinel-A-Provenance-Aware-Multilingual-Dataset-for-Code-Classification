#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long power(long long x, long long y, long long M)
{
    long long res = 1;
    x = x % M; 

    if (x == 0)
        return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % M;

        y = y >> 1;
        x = (x * x) % M;
    }

    return res;
}

long long get_input()
{
    long long num;
    cin >> num;
    return num;
}

int main()
{
    long long A, B, M;
    A = get_input();
    B = get_input();
    M = get_input();

    cout << power(A, B, M);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 1)
        return 1;
    // int f = factorial(n - 1);
    // return f * n;

    return n * factorial(n - 1);
}
// int fibonacci(int n)
// {
//     // if (n == 0)
//     //     return 0;
//     // if (n == 1)
//     //     return 1;
//     if (n == 1 || n == 0)
//         return n;

//     return fibonacci(n - 1) + fibonacci(n - 2);
// }

vector<long long int> dp;
long long int fibo_optimized(long long int n)
{
    if (n < 2)
        return n;

    if (dp[n] != -1)
    {
        return dp[n];
    }

    else
    {
        dp[n] = fibo_optimized(n - 1) + fibo_optimized(n - 2);
    }
    return dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n;
    cin >> n;
    dp.assign(n + 5, -1);

    cout << fibo_optimized(n);
    return 0;
}
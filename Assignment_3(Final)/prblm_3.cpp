#include <bits/stdc++.h>
using namespace std;

int n, mx_w;
vector<int> value, weight;
vector<vector<int>> dp;

int knapsack(int i, int capacity)
{
    if (i < 0 || capacity <= 0)
        return 0;

    if (dp[i][capacity] != -1)
        return dp[i][capacity];

    if (weight[i] <= capacity)
    {
        int opn1 = knapsack(i - 1, capacity - weight[i]) + value[i];
        int opn2 = knapsack(i - 1, capacity);
        return dp[i][capacity] = max(opn1, opn2);
    }
    else
    {
        return dp[i][capacity] = knapsack(i - 1, capacity);
    }
}

void solve()
{
    cin >> n >> mx_w;

    weight.resize(n);
    value.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    dp.assign(n, vector<int>(mx_w + 1, -1));

    cout << knapsack(n - 1, mx_w) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
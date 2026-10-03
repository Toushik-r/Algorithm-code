#include <bits/stdc++.h>
using namespace std;

int n, mx_weight;
vector<int> value, weight;

int knapsack(int i, int capacity)
{
    if (i < 0 || capacity <= 0)
    {
        return 0;
    }

    if (weight[i] <= capacity)
    {
        int opn1 = knapsack(i - 1, capacity - weight[i]) + value[i];
        int opn2 = knapsack(i - 1, capacity);
        return max(opn1, opn2);
    }
    else
    {

        return knapsack(i - 1, capacity);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    value.resize(n);
    weight.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    cin >> mx_weight;

    cout << knapsack(n - 1, mx_weight);

    return 0;
}
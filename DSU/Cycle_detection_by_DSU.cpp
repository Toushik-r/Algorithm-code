#include <bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> dsu_group;

int find(int x)
{
    if (par[x] == -1)
    {
        return x;
    }

    cout << par[x] << endl;
    int l = find(par[x]);
    return l;
}

void dsu_union(int i, int j)
{
    int leader1 = find(i);
    int leader2 = find(j);

    if (dsu_group[leader1] > dsu_group[leader2])
    {
        par[leader2] = leader1;
        dsu_group[leader1] += dsu_group[leader2];
    }
    else
    {
        par[leader1] = leader2;
        dsu_group[leader2] += dsu_group[leader1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n >> t;

    par.assign(n, -1);
    dsu_group.assign(n, 1);

    bool cycle = false;

    while (t--)
    {
        int i, j;
        cin >> i >> j;
        int l1 = find(i);
        int l2 = find(j);
        if (l1 == l2)
            cycle = true;
        else
            dsu_union(i, j);
    }

    if (cycle)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
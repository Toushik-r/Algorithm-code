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

    // Path compression jog kora holo ebong extra cout shorano holo
    return par[x] = find(par[x]);
}

void dsu_union(int i, int j)
{
    int leader1 = find(i);
    int leader2 = find(j);

    if (leader1 != leader2)
    {
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
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;

    // 1-based indexing er jonno size n + 1
    par.assign(n + 1, -1);
    dsu_group.assign(n + 1, 1);

    int cycle_edges = 0; // Koyti edge cycle toiri kore tar count

    while (e--)
    {
        int i, j;
        cin >> i >> j;
        int l1 = find(i);
        int l2 = find(j);

        if (l1 == l2)
            cycle_edges++; // Eki group e thakle edge-ta cycle toiri korbe
        else
            dsu_union(i, j);
    }

    // Result print
    cout << cycle_edges << "\n";

    return 0;
}
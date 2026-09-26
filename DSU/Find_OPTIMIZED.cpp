#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> par;

int find(int x)
{
    if (par[x] == -1)
    {
        return x;
    }

    cout << par[x] << endl;
    int l = find(par[x]);
    par[x] = l;
    return l;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n = 6;
    par.assign(n, -1);
    par[0] = 1;
    par[1] = -1;
    par[2] = 1;
    par[3] = 1;
    par[4] = 5;
    par[5] = 3;

    cout << find(4) << endl;
    cout << par[4];
    return 0;
}
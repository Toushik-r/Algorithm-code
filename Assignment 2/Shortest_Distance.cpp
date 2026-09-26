#include <bits/stdc++.h>
using namespace std;

long long INF = 1e18;
int n, e;
vector<vector<long long>> adj_mat;

void floyd_warshell()
{

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj_mat[i][k] != INF && adj_mat[k][j] != INF && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int s, d;
        cin >> s >> d;
        if (adj_mat[s][d] == INF)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << adj_mat[s][d] << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> e;

    adj_mat.assign(n + 1, vector<long long>(n + 1, INF));

    for (int i = 1; i <= n; i++)
        adj_mat[i][i] = 0;

    while (e--)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj_mat[a][b] = min(adj_mat[a][b], c);
    }

    floyd_warshell();

    return 0;
}
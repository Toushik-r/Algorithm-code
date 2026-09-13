#include <bits/stdc++.h>
using namespace std;
int INF = INT_MAX;
int n, e;
vector<vector<int>> adj_mat;

void floyd_warshell()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj_mat[i][k] != INF && adj_mat[k][j] != INF && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj_mat[i][j] != INF)
            {
                cout << adj_mat[i][j] << " ";
            }
            else
                cout << "INF ";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> e;
    adj_mat.assign(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
        adj_mat[i][i] = 0;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = c;
    }

    floyd_warshell();

    return 0;
}
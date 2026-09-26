#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int a, b;
    long long int c;
    Edge(int a, int b, long long int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
int n, e, s;
vector<long long int> dis;
vector<Edge> edge_list;
long long int INF = 1e18;

void bellman_ford()
{

    dis[s] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            long long int c = ed.c;
            if (dis[a] != INF && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
        }
    }

    bool cycle = false;
    for (auto ed : edge_list)
    {
        int a = ed.a;
        int b = ed.b;
        long long int c = ed.c;
        if (dis[a] != INF && dis[a] + c < dis[b])
            cycle = true;
    }

    if (cycle)
        cout << "Negative Cycle Detected\n";
    else
    {
        int t;
        cin >> t;
        while (t--)
        {
            int d;
            cin >> d;
            if (dis[d] == INF)
                cout << "Not Possible\n";

            else
                cout << dis[d] << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> e;

    dis.assign(n + 1, INF);
    while (e--)
    {
        int a, b;

        long long int c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    cin >> s;
    bellman_ford();

    return 0;
}
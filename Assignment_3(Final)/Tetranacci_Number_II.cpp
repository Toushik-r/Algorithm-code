#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    if (n == 1 || n == 2)
    {
        cout << 1 << "\n";
        return 0;
    }
    if (n == 3)
    {
        cout << 2 << "\n";
        return 0;
    }

    long long t0 = 0, t1 = 1, t2 = 1, t3 = 2;
    long long tn = 0;

    for (int i = 4; i <= n; i++)
    {
        tn = t0 + t1 + t2 + t3;

        t0 = t1;
        t1 = t2;
        t2 = t3;
        t3 = tn;
    }

    cout << tn << "\n";

    return 0;
}
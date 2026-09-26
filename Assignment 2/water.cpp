#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Shobcheye boro duiti element er index khuje ber kora
    int max1_idx = -1, max2_idx = -1;

    for (int i = 0; i < n; i++)
    {
        if (max1_idx == -1 || a[i] > a[max1_idx])
        {
            max2_idx = max1_idx;
            max1_idx = i;
        }
        else if (max2_idx == -1 || a[i] > a[max2_idx])
        {
            max2_idx = i;
        }
    }

    // Chhoto index age print korte hobe
    int left_idx = min(max1_idx, max2_idx);
    int right_idx = max(max1_idx, max2_idx);

    cout << left_idx << " " << right_idx << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }

    return 0;
}
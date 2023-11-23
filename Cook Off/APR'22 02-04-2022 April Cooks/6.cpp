#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
ll ans;
ll l = -1;
ll r = -1;
ll g = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    ll ans = 0;
    ll t = 0;
    for (auto it : mp)
    {
        if (it.second % 2 != 0)
        {
            ans++;
            it.second++;
        }
        t += it.second;
    }

    if (t % 4 == 0)
    {
        cout << ans << endl;
    }
    else
    {
        ll h = ans + 2;
        cout << h << endl;
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
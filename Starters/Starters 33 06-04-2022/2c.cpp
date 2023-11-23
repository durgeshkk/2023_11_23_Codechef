#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{
    ll x,y;
    cin>>x>>y;

    ll ans = y*30;
    if(ans <= (x)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return;
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
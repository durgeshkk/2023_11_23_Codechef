#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;

    if(n <= (m-k)){
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
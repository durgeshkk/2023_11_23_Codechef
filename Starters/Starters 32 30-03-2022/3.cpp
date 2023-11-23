#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{
    ll n,m;
    cin>>n>>m;

    ll r=0,l=0;
    if(n >= (m)){
        r = n;
        l = n-m;
    }
    else{
        r=n;
    }
    cout<<l+r<<endl;
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
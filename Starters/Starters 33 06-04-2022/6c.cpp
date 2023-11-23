#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{
    ll n;
    cin>>n;

    vector<ll> v;

    for(ll i=0;i<n;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
    }

    ll ans = 0,even = 0,odd=0;

    for(auto i=0;i < n;i++){
        if((v[i]%2) == 0){
            even++;
        }
        else{
            odd++;
        }
    }

    if(odd == 0 || even == 0){
        cout<<0<<endl;
        return;
    }

    if(odd%2 == 0 ){
        ans = min(odd/2,even);
        cout<<ans<<endl;
    }

    else{
        ans = even;
        cout<<ans<<endl;
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
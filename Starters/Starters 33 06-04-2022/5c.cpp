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

    ll sum = accumulate(v.begin(),v.end(),0);
    // cout<<sum<<endl;

    ll i=1;
    while(sum >= i){
        sum = sum - i;
        i++;
    }

    cout<<(i-1)<<endl;
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
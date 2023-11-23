#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{
    ll n;
    cin>>n;

    // vector<ll> v;
    string s;
    cin>>s;

/*
    for(ll i=0;i<n;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
    }
*/
    ll i=0;
    ll count_0=0;
    ll count_1=0;

    while(i<n){
        if(s[i] == '0'){
            count_0++;
        }
        else{
            count_1++;
        }
        i++;
    }
    
    i=0;
    while(i<n){
        if(s[i] == '0'){
            
        }
        i++;
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
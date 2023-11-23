#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n,r;
    cin>>n>>r;

    vector<ll> a;
    vector<ll> b;
    
    ll mn = INT16_MAX;

    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       a.push_back(ele);
       if(mn > ele){
           mn = ele;
       }
    }
    
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       b.push_back(ele);
    }

    vector <pair<ll,ll>> v;

    for(ll i=0;i<n;i++){
        ll diff = a[i]-b[i];
        pair<ll,ll> z;
        z.first = diff;
        z.second = a[i];
        v.push_back(z);
    }

    sort(v.begin(),v.end());
/*
   for(auto it:v){
       cout<<it.first<<" "<<it.second<<endl;
   }*/

    ll count=0;
   while(r >= mn){
       r -= 
   }
    
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   solve();
   return 0;
}
#include<bits/stdc++.h>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
 
void solve()
{
 
    ll n,q;cin>>n>>q;
    vector<ll> v(n);enter(v);
    vector<ll> prefix(n+1,0);
    for(ll i=0;i<q;i++){
        ll l,r;cin>>l>>r;
        prefix[l]++;prefix[r+1]--;
    }
    
    vector<ll> aads(n,0);
    multiset<pair<ll,ll>> kd;
    kd.insert({prefix[0],0});
    for(ll i=1;i<n;i++){
        prefix[i] += prefix[i-1];
        kd.insert({prefix[i],i});
    }

    sort(all(v));
    ll j = n-1;
    while(!kd.empty()){
        auto p = *kd.rbegin();kd.erase(kd.find(p));
        aads[p.second] = v[j];
        --j;
    }
    ll sm= 0;
    for(ll i=0;i<n;++i){
        sm += (prefix[i]*aads[i]);
    }
    show(aads);
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with aads now
   // use setprecision before aads
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}
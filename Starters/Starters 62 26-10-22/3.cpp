#include<bits/stdc++.h>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
 
    ll n,q;cin>>n>>q;
    vector<ll> v(n);enter(v);
    ll sm = 0;
    for(ll i=0;i<n;i++){sm+=v[i];}
    for(ll i=0;i<q;i++){
        ll a,b;cin>>a>>b;
        if((b-a)&1){}
        else{++sm;}
    }
    cout<<sm<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
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
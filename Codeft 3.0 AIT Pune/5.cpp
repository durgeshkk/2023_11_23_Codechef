#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
vector<ll> adj[200004];
ll ans;
vector<ll> vis;
vector<ll> v;
ll f = 0;
ll dfs(ll i,ll par){
    vis[i] = 1;
    for(auto it:adj[i]){
        if(!vis[it]){
            ll xr = dfs(it,i);
            if(xr == 1){
                ++ans;
                if(!v[i]){
                    v[i] = 1;
                }else{
                    v[i] = 0;
                }
                v[it] = 0;
            }
        }
    }
    
    if(v[i] == 1 and par != -1 and v[par] == 1){
        f = 1;
        v[i] = 0,v[par] = 0;++ans;
    }else if(v[i] == 1 and par != -1 and v[par] == 0){
        v[i] = 0,v[par] = 1;++ans;
    }else if(v[i] == 0 and par != -1 and v[par] == 0){
        f = 1;
    }
    // cout<<i<<" "<<v[i]<<endl;
    return v[i];
}

void solve()
{
    ans = 0;
    ll n;cin>>n;
    for(ll i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);adj[v].push_back(u);
    }
    v.assign(n+1,0);
    vis.assign(n+1,0);
    for(ll i=1;i<=n;i++){
        cin>>v[i];
    }
    // show(v);

    ll cntr = 0;
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            ++cntr;
            dfs(i,-1);
        }
    }

    // show(v);
    if(cntr > 1){cout<<"-1\n";return;}
    
    if(f & 1){
        for(auto it:v){if(it == 1){++ans;}}
    }else{
        for(auto it:v){if(it == 1){cout<<"-1\n";return;}}
    }
    cout<<ans<<endl;
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
//    cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}
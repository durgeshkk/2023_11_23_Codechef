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
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void solve()
{
 
    ll n;cin>>n;
    vector<ll> ag(n);enter(ag);
    vector<pair<ll,ll>> v;

    for(ll i=0;i<n;i++){
        ll flag = 0,cnt = 1;
        while(ag[i] == ag[i+1] and i<n-1){
            ++cnt;++i;
            if(i == n-1){
                v.push_back({ag[i],cnt});
                flag = 1;break;
            }
        }
        if(flag & 1){break;}
        v.push_back({ag[i],cnt});
    }

    vector<set<ll>> adj(n+1);
    multiset<ll> ms;
    n = v.size();
    for(ll i=0;i<n;i++){
        ms.insert(v[i].first);
        adj[v[i].first].insert(i);
    }

    ll mx = 0;
    for(ll i = 0;i<n;++i){
        ll cnt = 0;
        adj[v[i].first].erase(adj[v[i].first].find(i));
        ms.erase(ms.find(v[i].first));

        if(ms.find(v[i].first-1) != ms.end()){
            // cout<<v[i]<<endl;
            ll k = i;
            for(auto j:adj[v[i].first-1]){
                ll z = j;
                // cout<<z<<endl;
                while(k < j and z < n){
                    if(v[k].first == (v[z].first+1)){
                        cnt += (v[k].second*v[z].second);
                    }else{break;}
                    ++k,++z;
                }
                // cout<<"HI\n";
                mx = max(mx,cnt);
            }
        }
    }

    cout<<mx<<endl;
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
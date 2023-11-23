#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (998244353);
 
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    
    ll cnt = 0;
    multiset<ll> ms;
    vector<ll> z;
    for(ll i=0;i<n;i++){
        if(v[i] == 1){++cnt;}
        else if(v[i]&1){z.push_back(v[i]);}
        else{ms.insert(v[i]);}
    }
 
    while(cnt > 0 and !ms.empty()){
        ll val = *ms.begin();
        ms.erase((ms.find(val)));
        z.push_back(++val);
        --cnt;
    }

    while(cnt > 0){z.push_back(1);--cnt;}

    while(!ms.empty()){
        ll val = *ms.rbegin();
        ms.erase((ms.find(val)));
        z.push_back(val);
    }

    // show(z);
    ll ans = 1;
    for(ll i = 0;i<z.size();++i){
        ans = (((ans%mod)*z[i])%mod);
        // ans = mod_mul(ans,z[i],mod);
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
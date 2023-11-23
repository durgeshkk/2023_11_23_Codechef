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
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

ll power(ll base,ll n,ll mod){
   ll ans = 1;
   while( n!= 0){
      if(n%2){
          n-=1;
          ans = (ans*base)%mod;
      }
      else{
          n /= 2;
          base = (base*base)%mod;
      }
   }
   return ans;
}

vector<ll> fact(500010,0);
vector<ll> powfact(500010,0);
void precomputefact(){
   fact[0] = 1;
   ll ans = 1;
   for(ll i = 1;i<=500004;++i){
       ans = (ans*i)%mod;
       fact[i] = ans;
       powfact[i] = power(fact[i],mod-2,mod);
   }
   powfact[0] = 1;
}

ll nCr(ll n,ll r){
    ll at = powfact[r];
    ll at2 = powfact[n-r];
    at = mod_mul(at,at2,mod);
    ll ele = mod_mul(at,fact[n],mod);
    return ele;
}

vector<ll> ans(500005,0);
void solve()
{
 
    ll n;cin>>n;
    ll ans = 0,cntr = 0;
    for(ll i=0;i<=((n)/2);cntr++,i++){
        ll sa = nCr(n-i,cntr);
        ans = mod_add(ans,sa,mod);
    }
    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
    
    ans[0] = 1;
    ans[1] = 1;
    for(ll i = 2;i<=(500005);++i){
        ll ele = mod_add(ans[i-1],ans[i-2],mod);
        ans[i] = ele;
    }

   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
    //    solve();
        ll n;cin>>n;
        cout<<ans[n]<<endl;
       ++i;
   }
   //solve();
   return 0;
}
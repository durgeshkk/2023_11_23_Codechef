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
 
bool prime[1000005];
void SieveOfEratosthenes(){
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (ll p = 2; p * p <= 1e6; p++) {
        if (prime[p] == true) {
            for (ll i = p*p; i <= 1e6; i += p)
                prime[i] = false;
        }
    }
}
  
void solve()
{
 
    ll n;cin>>n;
    ll x = (n+1)/2;
    ll f = 0;
    for(ll i = 2;i<n;++i){
        if(prime[i] and prime[n-i]){
            f = i;break;
        }
    }
    if(!f){
        cout<<"-1\n";return;
    }else{
        // cout<<f<<" "<<n-f<<endl;
        // /*
        for(ll i = f+1;i<=n;++i){
            cout<<i<<" ";
        }
        for(ll i = 1;i<=f;++i){
            cout<<i<<" ";
        }
        cout<<endl;
        // */
    }
    return;

    if(n <= 2){cout<<"-1"<<endl;return;}
    vector<ll> ans;
    ll a = 1,b = 2;
    for(ll i=0;i<n;i++){
        ans.push_back(i+1);
        // if(v[i] & 1){
        //     ans.push_back(a);
        //     a += 2;
        // }else{
        //     ans.push_back(b);
        //     b += 2;
        // }
    }
    reverse(all(ans));
    show(ans);
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   SieveOfEratosthenes();
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